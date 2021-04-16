#include <bits/stdc++.h>

using namespace std;

void determine_genes(const string &child, const string &parent1, const string &parent2, map<string,string> &genes, map< string, vector<string> > &parents)
{
    if (genes.find(parent1) == genes.end())
    {
        determine_genes(parent1, parents[parent1][0], parents[parent1][1], genes, parents);
    }

    if (genes.find(parent2) == genes.end())
    {
        determine_genes(parent2, parents[parent2][0], parents[parent2][1], genes, parents);
    }

    bool has_gene = false;

    if (genes[parent1] != "non-existent" and genes[parent2] != "non-existent")
    {
        has_gene = true;
    }  else if (genes[parent1] == "dominant" or genes[parent2] == "dominant")
    {
        has_gene = true;
    }

    if (has_gene)
    {
        if (genes[parent1] == "dominant" and genes[parent2] == "dominant")
        {
            genes[child] = "dominant";
        } else if (genes[parent1] == "dominant" and genes[parent2] == "recessive")
        {
            genes[child] = "dominant";
        } else if (genes[parent1] == "recessive" and genes[parent2] == "dominant")
        {
            genes[child] = "dominant";
        } else {
            genes[child] = "recessive";
        }
    } else {
        genes[child] = "non-existent";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    string name, name_or_gene;
    int n; cin >> n;
    
    map<string,string> genes;
    map< string, vector<string> > parents;


    while (n--)
    {
        cin >> name >> name_or_gene;

        if (name_or_gene == "non-existent" or name_or_gene == "recessive" or name_or_gene == "dominant")
        {
            genes[name] = name_or_gene;
        } else
        {
            parents[name_or_gene].push_back(name);
        }
    }

    for (auto it = parents.begin(); it != parents.end(); it++)
    {
        determine_genes(it->first, (it->second)[0], (it->second)[1], genes, parents);
    }

    for (auto it = genes.begin(); it != genes.end(); it++)
    {
        cout << it->first << " " << it->second << '\n';
    }
}