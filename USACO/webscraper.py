import requests
from bs4 import BeautifulSoup

url = "https://usaco.org/index.php?page=contests"
response = requests.get(url)

html_content = response.text
soup = BeautifulSoup(html_content, "html.parser")

freshman = input("Enter freshman graduation year: ")
senior = input("Enter senior graduation year: ")

contests = soup.find_all('a')

count = 0;

for contest in contests:
    contest_url = contest.get('href')
    if not contest_url or "results" not in contest_url:
        continue
    if not contest_url.startswith('http'):
        contest_url = requests.compat.urljoin(url, contest_url)
    print("scraping " + contest_url)

    contest_response = requests.get(contest_url)
    contest_html_content = contest_response.text
    contest_soup = BeautifulSoup(contest_html_content, "html.parser")

    results = contest_soup.find_all('a')

    for result in results:
        result_url = result.get("href")
        if not result_url or "gold" not in result_url or "results" not in result_url:
            continue
        if not result_url.startswith('http'):
            result_url = requests.compat.urljoin(url, result_url)
        print("scraping " + result_url) 

        result_response = requests.get(result_url)
        result_html_content = result_response.text
        result_soup = BeautifulSoup(result_html_content, "html.parser")

        table = result_soup.find('table')
        if table:
            for row in table.find_all('tr'):
                cells = row.find_all(['th', 'td'])
                country = cells[0].get_text(strip=True)
                year = cells[1].get_text(strip=True)

                # Check if the cell value matches the target value
                if country == "USA" and senior <= year <= freshman: 
                    count += 1

print("Total USA high-school students in the USACO Platinum division: " + str(count))