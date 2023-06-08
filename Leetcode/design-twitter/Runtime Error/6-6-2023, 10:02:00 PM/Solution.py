// https://leetcode.com/problems/design-twitter

from typing import List
from collections import defaultdict
from heapq import heappush, heappop


class Twitter:
    def __init__(self):
        self.infoMap = defaultdict(list)
        self.count = 1

    def postTweet(self, userId: int, tweetId: int) -> None:
        if userId not in self.infoMap:
            self.infoMap[userId] = [[], set()]
        self.infoMap[userId][0].append((-self.count, tweetId))
        if len(self.infoMap[userId][0]) > 10:
            self.infoMap[userId][0].pop(0)
        self.count += 1

    def getNewsFeed(self, userId: int) -> List[int]:
        heap = []

        for tweet in self.infoMap[userId][0]:
            heappush(heap, tweet)
            if len(heap) > 10:
                heappop(heap)
        # Add the tweets from the user's followees to the heap
        for followee in self.infoMap[userId][1]:
            for tweet in self.infoMap[followee][0]:
                heappush(heap, tweet)
                if len(heap) > 10:
                    heappop(heap)

        return [tweet for _, tweet in sorted(heap)]

    def follow(self, followerId: int, followeeId: int) -> None:

        if followerId != followeeId and followeeId not in self.infoMap[followerId][1]:
            self.infoMap[followerId][1].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:

        if followeeId in self.infoMap[followerId][1]:
            self.infoMap[followerId][1].remove(followeeId)