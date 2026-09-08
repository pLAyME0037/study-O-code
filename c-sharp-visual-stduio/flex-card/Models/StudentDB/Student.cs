using SQLite;

namespace user_info.Models.StudentDB;

public class Student
{
    [PrimaryKey, AutoIncrement]
    public int Id       { get; set; } = 0;
    [MaxLength(50)]
    public string Name  { get; set; } = string.Empty;
    public string Sex   { get; set; } = string.Empty;
    public string Email { get; set; } = string.Empty;
    public string Major { get; set; } = string.Empty;
    public int Age      { get; set; } = 0;
}


