#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

int main(){
    int n [] = {12,11,10,8,9,6,7,5,4,1,2,3};
    bitset<16> bitstr =  bitset<16>(-1);
    cout << bitstr to_string() << endl;
    /*sort(n, n+12, less<int>());
    int a[4];
    int ans = 1e9;
    do{
        a[0] = n[0]+n[1]+n[2];
        a[1] = n[3]+n[4]+n[5];
        a[2] = n[6]+n[7]+n[8];
        a[3] = n[9]+n[10]+n[11];
        sort(a, a+4);
        if(a[3]-a[0]< ans) ans = a[3]-a[0];

    }while (next_permutation(n, n+12));
    cout << ans << endl;


    */
    return 0;
}
/*
                                                                                                    
                                                                                                    
                                   ^~~!!!~~^:                                                       
                               :!?7!~^^^^^~!777~                                                    
                             ^??^             :!J~ ::^^^^^^:::                                      
                            :J:                  5J!!!~~~~!!!7777!~^:                               
                           J?                    J?              :^~777~:                           
                          ^P                 :^!??                    :~7?!:     ::::               
                          ~5               ~J7~^                          ^?J!777!!!!777!^          
                           P^              5~                             7J7^         :~7?!        
                          :J5^             Y7                           :57                !J~      
                        :J! :J7:           5~                           5!                   Y7     
                      ^J7     ~??!^:    :!J!                            5!                    5~    
                     7J:         ^!!7777!~                              :??!~^                !Y    
                    J7                                                     :~!J!              ^5    
                  :5!                                                          P^             7J    
                  5!                                                           5~            ~5:    
                 J?                                                            Y!          :7J:     
                :P                ?PBGY:     :::^^:::                          ^5~:   ::~!?7^       
                7J               !@@@@@5^!777!!!!!!!7777!^:                     :!77?Y!!~^          
                Y!                JGB&#Y!^              ^!7?!:                      :P              
                Y!                  JJ:                     ~??^                     P:             
                :?                 J?         :^              :??    ::              P:             
                ^5                ^P        ~J!7Y      ^:       7Y !G##B?           :P              
                 :?               ^P       ^5:  P^   ??!J!       J?P@@@@&:          7J              
                  :Y:              Y7      !5  ??   J?  7Y       ~Y:JPPY~          :P:              
                 :J7??^             Y7      777~    5~ !Y:       J?                Y!               
                ^5^  ^??!:           7J!            :77!        ?J                J7                
                5^      ~7?7~^         !?7~:                 :!J!                Y7                 
               J7          :~!777!~^:    :!777~^:::    ::^~!?7~                ~Y~                  
              :5                :^~!777!~^:  :^~~!!!7777!!~:                 ~??:                   
              ~Y::                    ::^~!777!!~^::                   :^~!J?~:                     
            :?7!~!7?!:                !!      ::^~!!!777777!!!!!!!77777!!^:^J^                      
       ^^^^!?       ~J7  ^~            ??              :   ::::::::      :~~?5!^                    
     7?!~~~!        :??Y^ Y:            JJ            7!            ~  ~J7~:: ^!J^ :~~~:            
    7Y            ~??^ :5~^5     :~!777!~Y?          ??            ^5 7Y!       :7^^^^~7J~          
    :?        :~7?!:     5^7J :7?!~:      P^        !5:^^^^::      7J~5 :?7:            :Y!         
    ^P:::^~!777~:        ^5 ?Y~:    ~     Y7        5~:^~~~!!777~: 5~5:   ~7?!^          :P         
     75^~~^:              5~ 7J^   !Y~7!~7J        :P          :~!YJ^5       ^!777!~~^~~~!P         
      7J                  5~  ^??!7J:  ^^:          5!  :!Y~     ~5 ~5           :^^~~~^!P~         
       :Y~               !Y      ::                  !777^^5^  :7J:  P:                7J:          
        :??~           :7Y!~^:                             :7777^    !5:            :7J~            
          :!?7!~^^^~!7?7~  :^!77!~^:                             ^~!777J7^      :^!??^              
              ^~~~~~^:          :^~!7777!!~~^^^::::::^^^^~~!!7777!~^    ^!7777777!^                 
                                       ::^^~~~!!!!!!!!!~~~^::                                       
                                                                                                    




                                                            
                    :^^^^^^:                                
                 :~~^:   :^~!^ ::::::                       
                ^7:          77^^^^^^~~~~^:                 
                :          ^^!:          :^~~: :::::        
                J        :?::               ^?!^^:^^~!~     
               ~77       :?                !7         ^7^   
             ^7^ :!~^:::^!^                ?:           ?:  
            ::      :^^^^                   ~~~^        ^7  
           7^                                  ?:       !~  
          :~                                   !~      ~!   
         :?         J##J:^^~~~~^^::            :!~~~~~~:    
         ^7         7P#Y^::     :^~~~:            ^?        
         ^7          7^     :       :!!   :       :?        
          :         ^?    ~~!!  ^~:   ^7J&&Y      ^7        
          :J^        ?:   ?:!^ 7^~?    ?75P7      ?:        
          7~~!^      :7^   ^:  !~!    ^7         !~         
         7~   ^~~~^:   ^~~^:       :^!~         !~          
        :?        :^~~~^^^~~~~~~~~~^:        :^!^           
       :!7~~:          ~::^^~~~~^^^^^^^^^^~~~?~             
   :~~~!    !7 ^       ~!       :^:::::::: ^~~7~:           
  ^7      :~!^7~7  :^~~^7!      7       ~~!7:   ~^^^~~      
  ~7 ::^~~~:   ?!7~^::   ?:    7!^~~~^: 7?~ ~~:      ~!     
   7!^^:       ~!^7: 7~~~!     J  :: ::7??   :^~~~~^^77     
    :~         7^  ^^:         ~~~~7: ^7 ?:        :!7      
     ^!~:: ::^!!^^^:                ^^^ :!?^     :~!^       
       :^^^^^:    :^^~~~~^^^^^^^^^^~~~~~^: ^~~~~~^:         
                          :::::::::                         


https://www text-image com/convert/result cgi
*/