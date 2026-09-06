using SQLite;
using user_info.Models;

namespace user_info.Services;

public class ProdCateDBService 
{
    private SQLiteAsyncConnection? _database;

    public async Task InitializeDatabaseAsync() {
        if (_database != null) { return; }

        string baseDir;
        try {
            baseDir = FileSystem.Current.AppDataDirectory;
        } catch (Exception) {
            baseDir = Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData);
        }
        string dbPath = Path.Combine(baseDir, "WU_HW_ProdCate.db3");

        _database = new SQLiteAsyncConnection(dbPath);
        await _database.CreateTableAsync<ProductCate>();
    }

    public async Task<List<ProductCate>> GetProdAsync() {
        await InitializeDatabaseAsync();
        return await _database!.Table<ProductCate>().ToListAsync();
    }

    public async Task<List<ProductCate>> SearchProdsByNameAsync(string name) {
        await InitializeDatabaseAsync();
        return await _database!.Table<ProductCate>()
                               .Where(f => f.Name.Contains(name))
                               .ToListAsync();
    }

    public async Task<List<string>> GetDistinctCateAsync() {
        string sql = @"SELECT DISTINCT Categlory
                       FROM ProductCate
                       WHERE Categlory IS NOT NULL AND Categlory<>''
                       ORDER BY Categlory";
        return await _database!.QueryScalarsAsync<string>(sql);
    }

    public async Task<List<ProductCate>> SearchProdsByCateAsync(string cate) {
        await InitializeDatabaseAsync();
        return await _database!.Table<ProductCate>()
                               .Where(f => f.Categlory.Contains(cate))
                               .ToListAsync();
    }
}


