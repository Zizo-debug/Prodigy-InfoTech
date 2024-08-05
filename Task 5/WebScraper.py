import requests
from bs4 import BeautifulSoup
import csv

req = requests.get('https://sandbox.oxylabs.io/products')
soup = BeautifulSoup(req.text, 'html.parser')

# names
div_names = soup.find_all("h4", {"class": "title"})
# prices
div_price = soup.find_all("div", {"class": "price-wrapper"})
# ratings
svg_elements = soup.find_all('svg', xmlns="http://www.w3.org/2000/svg")

# Prepare data for CSV
data = []
for i, (name_div, price_div) in enumerate(zip(div_names, div_price)):
    name = name_div.get_text().strip()
    price = price_div.get_text().strip()

    # Count stars for this product
    star_count = 0
    for svg in svg_elements[i * 5:(i + 1) * 5]:  # Assuming 5 SVGs per product
        path_elements = svg.find_all('path')
        if path_elements:
            star_count += 1

    data.append([name, price, star_count])

# Write to CSV file
with open('products.csv', 'w', newline='', encoding='utf-8') as csvfile:
    csv_writer = csv.writer(csvfile)
    csv_writer.writerow(['Name', 'Price', 'Rating'])  # Write header
    csv_writer.writerows(data)

print("Data has been written to products.csv")