class Solution {
public:
      long long solve(string word, int k) {
        unordered_map<char, int> vowels;
        int consonant = 0, count = 0;
        int i = 0;
        long long result = 0;

        for (int j = 0; j < word.size(); j++) {
            char ch = word[j];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels[ch]++;
            } else {
                consonant++;
            }

            while (vowels.size() == 5 && consonant > k) {
                char left = word[i];
                if (left == 'a' || left == 'e' || left == 'i' || left == 'o' || left == 'u') {
                    vowels[left]--;
                    if (vowels[left] == 0) vowels.erase(left);
                } else {
                    consonant--;
                }
                i++;
            }

            result += (j - i + 1);
        }

        return result;
    }

    long long countOfSubstrings(string word, int k) {
        return solve(word, k) - solve(word, k - 1);
    }
};