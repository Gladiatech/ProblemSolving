#pragma once

#include<unordered_map>
#include<list>

using namespace std;
class LRUCache
{

public:

    LRUCache(size_t cap) :capacity(cap) {}

    int get(const int& key);

    void put(const int& key, const int& value);

private:

    bool exist(const int& key);
    void clean();
    size_t capacity;
    list<pair<int, int>>pages;
    unordered_map<int, decltype(pages.begin())> cache;


};

int LRUCache::get(const int& key)
{

    if (!exist(key)) return -1;

    auto it = cache.find(key);
    pages.splice(pages.begin(), pages, it->second);
    return it->second->second;

}


void LRUCache::clean()
{

    while (cache.size() > capacity)
    {

        auto it_last = pages.end();
        it_last--;
        cache.erase(it_last->first);
        pages.pop_back();

    }

}

bool LRUCache::exist(const int& key)
{

    return(cache.count(key) > 0);

}

void LRUCache::put(const int& key, const int& value)
{

    auto it = cache.find(key);
    if (it != cache.end())
    {
        pages.erase(it->second);
        cache.erase(it);
    }
    pages.push_front(make_pair(key, value));
    cache.insert(make_pair(key, pages.begin()));
    clean();

}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */