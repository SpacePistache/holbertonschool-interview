#!/usr/bin/python3
"""Recursively count keywords in the titles of a subreddit's hot posts."""
import requests


def count_words(subreddit, word_list, after=None, counts=None):
    """Print a sorted count of the given keywords found in hot titles."""
    if counts is None:
        counts = {}
        for word in word_list:
            counts[word.lower()] = 0

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {"User-Agent": "holberton:count_it:v1.0 (by /u/student)"}
    params = {"limit": 100, "after": after}
    try:
        response = requests.get(url, headers=headers, params=params,
                                allow_redirects=False)
        if response.status_code != 200:
            return
        data = response.json().get("data", {})
    except Exception:
        return

    for post in data.get("children", []):
        title_words = post.get("data", {}).get("title", "").lower().split()
        for word in word_list:
            counts[word.lower()] += title_words.count(word.lower())

    after = data.get("after")
    if after is not None:
        return count_words(subreddit, word_list, after, counts)

    for word, count in sorted(counts.items(), key=lambda kv: (-kv[1], kv[0])):
        if count > 0:
            print("{}: {}".format(word, count))
