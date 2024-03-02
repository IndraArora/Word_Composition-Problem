#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

// Comparator function for sorting strings by length
bool compareByLength(string a, string b)
{
    return a.size() < b.size();
}

void readFileInput(vector<string> &word_list)
{
    // Check if input file is present or throw error
    ifstream inputFile("Input_02.txt");
    if (!inputFile.is_open())
    {
        cout << "Error opening file." << endl;
        return;
    }

    // Constructing words list from input file
    string word;
    while (getline(inputFile, word))
    {
        word_list.push_back(word);
    }
    inputFile.close();
}

vector<string> word_list;
vector<string> compounded_words;
int findCompoundedWord()
{
    readFileInput(word_list);

    int list_size = word_list.size();
    sort(word_list.begin(), word_list.end(), compareByLength);

    map<string, bool> words;
    for (int i = 0; i < list_size; i++)
    {
        bool flag = true;
        set<int> index;
        index.insert(-1);
        for (int j = 0; j < word_list[i].size(); j++)
        {
            for (auto it : index)
            {
                if (words.find(word_list[i].substr(it + 1, j - it)) != words.end())
                    index.insert(j);
            }
        }
        if (index.find(word_list[i].size() - 1) != index.end())
        {
            compounded_words.push_back(word_list[i]);
        }
        words[word_list[i]] = true;
    }

    sort(compounded_words.begin(), compounded_words.end(), compareByLength);
    return compounded_words.size();
}

// Function to print output
void printOutput(int ans, auto duration)
{
    cout << "Longest Compounded Word: " << compounded_words[ans - 1] << endl;
    cout << "Second Longest Compounded Word: " << compounded_words[ans - 2] << endl;
    cout << "Time taken by code: " << duration.count() << " milliseconds" << endl;
}

int main()
{
    // Fast Input Output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Calculate time required to run the code
    auto start = high_resolution_clock::now();
    int ans = findCompoundedWord();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    printOutput(ans, duration);

    return 0;
}