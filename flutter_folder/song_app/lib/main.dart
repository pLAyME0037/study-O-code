import 'package:flutter/material.dart';
import 'package:on_audio_query/on_audio_query.dart';
import 'package:audio_manager/audio_manager.dart';
import 'package:permission_handler/permission_handler.dart';

void main() {
  runApp(MaterialApp(
    theme: ThemeData(primarySwatch: Colors.cyan),
    home: SongApp(),
  ));
}

class SongApp extends StatefulWidget {
  @override
  _SongAppState createState() => _SongAppState();
}

class _SongAppState extends State<SongApp> {
  final OnAudioQuery _audioQuery = OnAudioQuery();
  final AudioManager audioManagerInstance = AudioManager.instance;

  double _slider = 0;
  bool isPlaying = false;

  @override
  void initState() {
    super.initState();
    setupAudio();
    requestPermission();
  }

  // Request storage permissions so songs show up
  void requestPermission() async {
    await Permission.storage.request();
    setState(() {});
  }

  void setupAudio() {
    audioManagerInstance.onEvents((events, args) {
      switch (events) {
        case AudioManagerEvents.start:
          setState(() => _slider = 0);
          break;
        case AudioManagerEvents.seekComplete:
          setState(() {
            _slider = audioManagerInstance.position.inMilliseconds /
                audioManagerInstance.duration.inMilliseconds;
          });
          break;
        case AudioManagerEvents.playstatus:
          setState(() => isPlaying = audioManagerInstance.isPlaying);
          break;
        case AudioManagerEvents.timeupdate:
          setState(() {
            _slider = audioManagerInstance.position.inMilliseconds /
                audioManagerInstance.duration.inMilliseconds;
          });
          audioManagerInstance.updateLrc(args["position"].toString());
          break;
        case AudioManagerEvents.ended:
          audioManagerInstance.next();
          break;
        default:
          break;
      }
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text("Music Player")),
      body: Column(
        children: [
          Expanded(
            child: FutureBuilder<List<SongModel>>(
              future: _audioQuery.querySongs(
                sortType: SongSortType.DATE_ADDED,
                orderType: OrderType.DESC_OR_GREATER,
                uriType: UriType.EXTERNAL,
              ),
              builder: (context, snapshot) {
                if (snapshot.data == null) return CircularProgressIndicator();
                if (snapshot.data!.isEmpty) return Center(child: Text("No Songs Found"));

                return ListView.builder(
                  itemCount: snapshot.data!.length,
                  itemBuilder: (context, index) {
                    SongModel song = snapshot.data![index];
                    return ListTile(
                      title: Text(song.title),
                      subtitle: Text(song.artist ?? "Unknown"),
                      leading: QueryArtworkWidget(id: song.id, type: ArtworkType.AUDIO),
                      onTap: () {
                        // This starts the actual song playback
                        audioManagerInstance.start(
                          song.data, // File path
                          song.title,
                          desc: song.artist ?? "",
                          auto: true,
                          cover: "", 
                        ).then((err) => print(err));
                      },
                    );
                  },
                );
              },
            ),
          ),
          bottomPanel(), // The controls at the bottom
        ],
      ),
    );
  }

  Widget bottomPanel() {
    return Container(
      padding: EdgeInsets.all(16),
      color: Colors.grey[100],
      child: Column(
        mainAxisSize: MainAxisSize.min,
        children: <Widget>[
          songProgress(context),
          Row(
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: <Widget>[
              CircleAvatar(
                child: IconButton(
                  icon: Icon(Icons.skip_previous, color: Colors.white),
                  onPressed: () => audioManagerInstance.previous(),
                ),
                backgroundColor: Colors.cyan,
              ),
              CircleAvatar(
                radius: 30,
                child: IconButton(
                  onPressed: () => audioManagerInstance.playOrPause(),
                  icon: Icon(isPlaying ? Icons.pause : Icons.play_arrow, color: Colors.white),
                ),
              ),
              CircleAvatar(
                backgroundColor: Colors.cyan,
                child: IconButton(
                  icon: Icon(Icons.skip_next, color: Colors.white),
                  onPressed: () => audioManagerInstance.next(),
                ),
              ),
            ],
          ),
        ],
      ),
    );
  }

  Widget songProgress(BuildContext context) {
    return Row(
      children: <Widget>[
        Text(_formatDuration(audioManagerInstance.position)),
        Expanded(
          child: Slider(
            value: _slider.isNaN || _slider.isInfinite ? 0 : _slider,
            onChanged: (value) {
              setState(() => _slider = value);
            },
            onChangeEnd: (value) {
              if (audioManagerInstance.duration != null) {
                Duration msec = Duration(
                  milliseconds: (audioManagerInstance.duration.inMilliseconds * value).round(),
                );
                audioManagerInstance.seekTo(msec);
              }
            },
          ),
        ),
        Text(_formatDuration(audioManagerInstance.duration)),
      ],
    );
  }

  String _formatDuration(Duration? d) {
    if (d == null) return "00:00";
    int minute = d.inMinutes;
    int second = (d.inSeconds % 60);
    return "${minute.toString().padLeft(2, '0')}:${second.toString().padLeft(2, '0')}";
  }
}
