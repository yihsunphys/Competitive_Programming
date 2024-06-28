int upper_bound(int *a, int begin, int end, int key) {
  int first = begin, last = end-1;
  int middle, pos = begin;       
  while(first < last){
    middle = (first+last)/2;
    if(a[middle] <= key){ 
        first = middle + 1;  
        pos = first;   
    }
    else{
        last = middle;   
        pos = last;                    
    }
  }
  return pos;
}