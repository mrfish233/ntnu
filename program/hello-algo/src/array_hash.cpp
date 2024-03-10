#include "array_hash.h"

Pair::Pair(int key, std::string val) {
    this->key = key;
    this->val = val;
};

ArrayHash::ArrayHash() {
    buckets = std::vector<Pair *>(100);
}

ArrayHash::~ArrayHash() {
    for (auto const &bucket : buckets) {
        delete bucket;
    }

    buckets.clear();
}

int ArrayHash::hash(int key) {
    return key % 100;
}

std::string ArrayHash::get(int key) {
    int idx = hash(key);

    Pair *pair = buckets[idx];

    if (pair == nullptr) {
        return "";
    }

    return pair->val;
}

void ArrayHash::put(int key, std::string val) {
    Pair *pair = new Pair(key, val);
    int idx = hash(key);

    buckets[idx] = pair;
}

void ArrayHash::remove(int key) {
    int idx = hash(key);

    delete buckets[idx];

    buckets[idx] = nullptr;
}

std::vector<Pair *> ArrayHash::getPairs() {
    std::vector<Pair *> pairSet;

    for (auto pair : buckets) {
        if (pair == nullptr) {
            continue;
        }

        pairSet.push_back(pair);
    }

    return pairSet;
}

std::vector<int> ArrayHash::getKeys() {
    std::vector<int> keySet;

    for (auto pair : buckets) {
        if (pair == nullptr) {
            continue;
        }

        keySet.push_back(pair->key);
    }

    return keySet;
}

std::vector<std::string> ArrayHash::getValues() {
    std::vector<std::string> valueSet;

    for (auto pair : buckets) {
        if (pair == nullptr) {
            continue;
        }

        valueSet.push_back(pair->val);
    }

    return valueSet;
}

void ArrayHash::print() {
    for (auto pair : getPairs()) {
        std::cout << pair->key << " -> " << pair->val << "\n";
    }
}
