int maxNumberOfPeople(vector<int>& rooms, vector<int>& people, int k) {
    sort(rooms.begin(), rooms.end());
    sort(people.begin(), people.end());

    int maxPeopleCount = 0;
    int roomIndex = 0;

    for (int i = 0; i < people.size(); ++i) {
        while (roomIndex < rooms.size() && rooms[roomIndex] < people[i] - k) {
            roomIndex++;
        }

        if (roomIndex < rooms.size() && rooms[roomIndex] <= people[i] + k) {
            maxPeopleCount++;
            roomIndex++;
        }
    }

    return maxPeopleCount;
}