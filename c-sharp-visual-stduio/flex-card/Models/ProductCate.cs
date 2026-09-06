using SQLite;
namespace user_info.Models;

public class ProductCate
{
    [PrimaryKey, AutoIncrement]
    public int    Id       { get; set; }
    [MaxLength(24)]
    public string Name     { get; set; } = string.Empty;
    public string Price    { get; set; } = string.Empty;
    public string Categlory { get; set; } = string.Empty;
}
