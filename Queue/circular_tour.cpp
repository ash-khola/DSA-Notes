// Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
// 1. The amount of petrol that every petrol pump has.
// 2. Distance from that petrol pump to the next petrol pump.
// Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
// Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

// Solution:
// We will keep inserting the index in queue while traversing the petrolPump array, and will keep adding the total distance covered and total total petrol consumed, at after addition of any index, if we found that petrol < destance than we will simply remove the front element of the queue(making sure that the remove index can't be our answer index) and when the size of the queue becomes equal to n than we can assure that all indexes are present in the queue with the condition (petrol > distanc) and the front index of the queue was our staring point and so is the answer to the solution. 

int tour(petrolPump P[],int n) {
    int total_petrol = 0, total_distance = 0;
    
    for(int i = 0; i < n; i++) {
        total_petrol += P[i].petrol;
        total_distance += P[i].distance;
    }
    
    if(total_petrol < total_distance) {
        return -1;
    }
    
    queue<int> q;
    
    int petrl = 0, dist = 0, index = 0;
    
    while(q.size() < n) {
        q.push(index);
        petrl += P[index].petrol;
        dist += P[index].distance;
        
        if(petrl < dist) {
            while(petrl < dist) {
                int i = q.front();
                q.pop();
                petrl -= P[i].petrol;
                dist -= P[i].distance;
            }
        }
        
        if(index == n-1) {
            index = 0;
        }
        else {
            index++;
        }
    }
    
    return q.front();
}

// Expected Time Complexity: O(N)
// Expected Auxiliary Space : O(N)