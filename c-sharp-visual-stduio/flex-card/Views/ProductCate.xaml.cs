using user_info.Models;
using user_info.Services;

namespace user_info.Views;

public partial class ProductCate : ContentPage
{
    private readonly ProdCateDBService _dbService;

    public ProductCate() {
        InitializeComponent();
        _dbService = new ProdCateDBService();
    }

    protected override async void OnAppearing() {
        base.OnAppearing();
        try {
            await _dbService.InitializeDatabaseAsync();

            var prod = await _dbService.GetProdAsync();
            ProductCollectionView.ItemsSource = prod;

            var cate = await _dbService.GetDistinctCateAsync();
            PickerCateglory.ItemsSource = cate;
        } catch (Exception ex) {
            await DisplayAlertAsync("Error: ", ex.Message, "OK");
        }
    }

    protected async void OnSearchNameClicked(object sender, EventArgs e) {
        try {
            string searchName = SearchEntry.Text?.Trim() ?? "";
            if (string.IsNullOrWhiteSpace(searchName)) {
                var students = await _dbService.GetProdAsync();
                ProductCollectionView.ItemsSource = students;
                return;
            }
            var results = await _dbService.SearchProdsByNameAsync(searchName);
            ProductCollectionView.ItemsSource = results;
        } catch (Exception ex) {
            await DisplayAlertAsync("Error: ", ex.Message, "OK");
        }
    }
    
    protected async void OnPickerCate(object sender, EventArgs e) {
        try {
            string pickerCate = PickerCateglory.SelectedItem.ToString() ?? "";
            if (string.IsNullOrWhiteSpace(pickerCate)) {
                var products = await _dbService.GetProdAsync();
                ProductCollectionView.ItemsSource = products;
                return;
            }
            var results = await _dbService.SearchProdsByCateAsync(pickerCate);
            ProductCollectionView.ItemsSource = results;
        } catch (Exception ex) {
            await DisplayAlertAsync("Error: ", ex.Message, "OK");
        }
    }
}


