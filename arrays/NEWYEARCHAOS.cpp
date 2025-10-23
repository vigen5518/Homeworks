void minimumBribes(std::vector<int> q){
    int bribes = 0;
    int position = q.size();
    for(int i=position-1; i>=0; --i){
        if(q[i] != i+1){
            if(i-1 >= 0 && q[i-1] == i+1){
                q[i-1] = q[i];
                q[i] = i+1;
                bribes +=1; 
            }
            else if(i -2 >= 0 && q[i-2] == i+1){
                q[i-2] = q[i-1];
                q[i-1] = q[i];
                q[i] = i+1;
                bribes += 2;
            }
            else {
                cout <<"Too chaotic" << endl;
                return;
            }
        }
    }
    cout <<bribes << endl;
}

