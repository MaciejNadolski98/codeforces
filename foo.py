import requests
from bs4 import BeautifulSoup

def print_secret_word(url):
    r = requests.get(url)
    soup = BeautifulSoup(r.content, 'html.parser')

    lines = []

    def add(x, y, char):
        while len(lines) <= y:
            lines.append([])
        while len(lines[y]) <= x:
            lines[y].append(" ")
        lines[y][x] = char

    for row in soup.find('table').find_all('tr')[1:]:
        spans = row.find_all('span')
        x, y, char = int(spans[0].get_text()), int(spans[2].get_text()), spans[1].get_text()
        add(x, y, char)
        
    for line in lines:
        print("".join(line))

if __name__=="__main__":
    print_secret_word("https://docs.google.com/document/d/e/2PACX-1vSvM5gDlNvt7npYHhp_XfsJvuntUhq184By5xO_pA4b_gCWeXb6dM6ZxwN8rE6S4ghUsCj2VKR21oEP/pub")
