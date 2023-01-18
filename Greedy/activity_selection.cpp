// N meetings in one room
// There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
// What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

// Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting

struct meeting
{
    int start;
    int end;
    // int pos;
};

static bool comparator(meeting m1, meeting m2)
{
    return m1.end < m2.end;
}

public:
int maxMeetings(int start[], int end[], int n)
{

    struct meeting meet[n];

    for (int i = 0; i < n; i++)
    {
        meet[i].start = start[i];
        meet[i].end = end[i];
        // meet[i].pos = i+1;
    }

    sort(meet, meet + n, comparator);

    int answer = 1, limit = meet[0].end;

    for (int i = 1; i < n; i++)
    {
        if (meet[i].start > limit)
        {
            answer++;
            limit = meet[i].end;
        }
    }

    return answer;
}

// Time Complexity : O(N *LogN)
// Auxilliary Space : O(N)