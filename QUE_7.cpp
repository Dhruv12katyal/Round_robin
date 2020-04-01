  #include<bits/stdc++.h>
  using namespace std;

  struct proc {
      string process_name;
      int Arival_T, burst_time, completion_time, remaining;
  }X_Struct;

  bool cmpl(proc A,proc B)
  {
    return (A.Arival_T<B.Arival_T);
  }

  void Facul_que(int no_of_process) {

      int count, Time_of_Arrival, burst_Time, Time_Quantum;
      struct proc Facul_Pro[no_of_process];

      for(count = 0; count < no_of_process; count++) {
          printf("write the detail of process[%d]", count+1);
          puts("");
          printf("Name of Process: ");
  
          cin>>Facul_Pro[count].process_name;
          printf("Arrival Time : ");
          scanf("%d", &Facul_Pro[count].Arival_T);

          printf("Burst Time : ");
          scanf("%d", &Facul_Pro[count].burst_time);
          puts("");
      }
      printf("Write the  quantum time for FACULTY queue : ");
      scanf("%d", &Time_Quantum);


      vector<int> final_result;
      
      sort(Facul_Pro,Facul_Pro+no_of_process,cmpl);
      for(int i=0;i<no_of_process;i++)
      {
          cout<<Facul_Pro[i].process_name<<" "<<endl;
      }
      
      for(count = 0; count < no_of_process; count++) {
          Facul_Pro[count].remaining = Facul_Pro[count].burst_time;
          Facul_Pro[count].completion_time = 0;
      }

      int total_time;
      total_time = 0;
  
      queue<proc> R_R;
      int processes=0;
  
      int flag, x, n, z, waiting_time = 0;
      do {

            if(processes<no_of_process)
            {
              while(processes< no_of_process && Facul_Pro[processes].Arival_T<=total_time)
              {
                R_R.push(Facul_Pro[processes++]);
              }
            }
          cout<<"Queue full: "<<R_R.size()<<endl;
            if(!R_R.empty())
            {

              proc cur_process= R_R.front(); R_R.pop();

              if(cur_process.remaining <= Time_Quantum)
              {
                   cout<<"process: "<<cur_process.process_name<<" completed in: "<<total_time+cur_process.remaining<<endl;
                    final_result.push_back(total_time+cur_process.remaining - cur_process.Arival_T);
                    total_time+=cur_process.remaining;
              }
              else
              {
                cur_process.remaining-=Time_Quantum;
                R_R.push(cur_process);
                total_time+=Time_Quantum;
              }
            }
            else
              total_time++;

      }while(!R_R.empty() || processes<no_of_process);
      
    int turn_around_time=0;
    for(int i=0;i<final_result.size();i++)
      turn_around_time+=final_result[i];
    
    cout<<"Total time spent on System: "<<total_time<<endl;
    cout<<"Average time per query: "<< (float)turn_around_time/no_of_process;
  }


  void student_Queue(int no_of_process) {

      int count, Time_of_Arrival, burst_Time, Time_Quantum;
      struct proc Facul_Pro[no_of_process];

      for(count = 0; count < no_of_process; count++) {
          printf("Write the details of process[%d]", count+1);
          puts("");
          printf("Name of Process: ");
  
          cin>>Facul_Pro[count].process_name;
          printf("Time_of_Arrival : ");
          scanf("%d", &Facul_Pro[count].Arival_T);

          printf("Burst Time : ");
          scanf("%d", &Facul_Pro[count].burst_time);
          puts("");
      }
      printf("Now, enter the quantum time for Student queue : ");
      scanf("%d", &Time_Quantum);


      vector<int> final_result;
  
      sort(Facul_Pro,Facul_Pro+no_of_process,cmpl);
      for(int i=0;i<no_of_process;i++)
      {
          cout<<Facul_Pro[i].process_name<<" "<<endl;
      }
  
      for(count = 0; count < no_of_process; count++) {
          Facul_Pro[count].remaining = Facul_Pro[count].burst_time;
          Facul_Pro[count].completion_time = 0;
      }

      int total_time;
      total_time = 0;

      queue<proc> R_R;
      int processes=0;
   
      int flag, x, n, z, waiting_time = 0;
      do {
            if(processes<no_of_process)
            {
            
              while(processes< no_of_process && Facul_Pro[processes].Arival_T<=total_time)
              {
                R_R.push(Facul_Pro[processes++]);
              }
            }
          cout<<"Queue full: "<<R_R.size()<<endl;
            if(!R_R.empty())
            {

              proc cur_process= R_R.front(); R_R.pop();

              if(cur_process.remaining <= Time_Quantum)
              {
                   cout<<"process: "<<cur_process.process_name<<" completed in: "<<total_time+cur_process.remaining<<endl;
                    final_result.push_back(total_time+cur_process.remaining - cur_process.Arival_T);
                    total_time+=cur_process.remaining;
              }
              else
              {
                cur_process.remaining-=Time_Quantum;
                R_R.push(cur_process);
                total_time+=Time_Quantum;
              }
            }
            else
              total_time++;

      }while(!R_R.empty() || processes<no_of_process);
      
    int turn_around_time=0;
    for(int i=0;i<final_result.size();i++)
      turn_around_time+=final_result[i];
    
    cout<<"Total time spent on System: "<<total_time<<endl;
    cout<<"Average time per query: "<< (float)turn_around_time/no_of_process;
  }
  int main(int argc, char const *argv[]) {
      int select_queue, no_of_process;

      puts("Please choose a queue to post your query : ");
      puts("1. FACULTY queue.");
      puts("2. STUDENT queue.");
      printf("> ");
      scanf("%d", &select_queue);

      switch(select_queue) {
          case 1 :
                  printf("Enter number of process for FACULTY queue : ");
                  scanf("%d", &no_of_process);

                  Facul_que(no_of_process);

                  break;

          case 2 :
                  printf("Enter number of process for STUDENT queue : ");
                  scanf("%d", &no_of_process);

                  student_Queue(no_of_process);

                  break;

          default :
                  printf("Please selet the correct option by running the program again.");
      }

      return 0;
  }


