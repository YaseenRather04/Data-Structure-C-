int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {

    int time = 0, front = 0;

    while(tickets[k] != 0){

        if(front == ticketsSize) front = 0;

        else {

            if(tickets[front] !=0){
                tickets[front]--;
                time++;
                front++;
            }

            else front++;
        }
    }
    return time;   
}
