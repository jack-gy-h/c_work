   <!-- 
    // 结果启示：如果传进去的是值的话，进去之后的值的地址和原来主函数的值的地址不一定一样

    // 因次传值进去之后根据地址修改相关的数据，不一定是主函数内传入参数的地址（也就是说并没有修改到相应的参数）

    // 当主函数再次使用该变量该地址下的数据时，也不会有所改变。
    
     -->
   
   
    //结构体基础：《C Primer Plus(第6版) 中文版》P441

    //指向data数组的组首元素的值

    //指针基础：《C Primer Plus(第6版) 中文版》 P267-275

    // malloc基础：《C Primer Plus(第6版) 中文版》P396

    //sizeof:《C Primer Plus(第6版) 中文版》 P113

    // 启示及注意事项：《C Primer Plus(第6版) 中文版》P297-298

    // 创建一个指针时，系统只分配了储存指针本身的内存，并未分配储存数据的内存。

    // 因此：

    //指针使用说明：

    //1.声明

    //2.为指针分配数据的地址

    // 再使用

   



    
    //*找出地址中的值

    // ∴ * + 地址（or指针）

    // & ＋ 变量

    //&找出变量中的地址

    <!-- 第一次学习启示：
    
    指针的作用：可以为主调函数(即int main())中调用的函数通过非return的方式对输入的变量进行值的更改

    当需要时，就需要更改变量为指针。

    但当只读时，则指针变量均可

    <!-- 核心要点：用在调用函数中非return方式修改主调函数中传入的变量时，需要使用指针 -->

    <!-- 《C Primer Plus(第6版) 中文版》 P267 -->
    
    
    
     -->


      <!-- T2.c启示： -->

    <!-- 顺序表的使用：

     <!-- 1.初始化(本质上是初始化结构体定义的内容:为指针分配空间以及为对象分配初始值)-->

      <!--2.创建一个顺序表(本质上是将结构体中需要填写的内容写到空表中
      
        <!-- (1)输入的数据写入初始化完成后的空顺序表  -->

        <!-- (2)将前面获取到的长度写到结构体中以便后面的使用 -->
       -->
      
      <!-- 3. 转置:
          <!-- (1)这里的elem是一个指针,在初始化的时候给它分配了initsize(100)个空间,由于写入的数据并不一定全满.

          顺序表是定长的,因此elem[-1]是指初始化分配的第99个位置,而并不一定是写入的数组的最后一个位置

          因此,数组的最后一个位置为:(L->length)-1


          elem[i]则是一个值 -->
      -->

      <!-- scanf的使用:
      
      转换字符＋地址(scanf是将获取到的值转换为相应的类型之后按地址将值写入,具体原因同使用地址的原因) 
      
      参考:   

      <!-- scanf基础：《C Primer Plus(第6版) 中文版》P92 -->

      <!-- scanf赋值的后一个变量是直接将值赋值到相应的指针上，原理和原因同指针的使用（非return方法修改传入值）--> 
      -->

      <!-- #define用法:
      
      <!--《C Primer Plus(第6版) 中文版》P522  -->

       -->


       <!-- typedef用法:
       
       <!-- 《C Primer Plus(第6版) 中文版》P478 -->

        -->
     -->


     <!-- T3.c启示： -->



     <!-- 在删除操作里，删除一个元素时： -->




     
     <!-- 可以从逐个移位和结果法分析 --> 

     <!-- 1.逐个移位：

      <!-- 只需要移动该元素后几位的元素，时间复杂度为：O(n)-->
      
       -->

     <!-- 2.结果法
       
       <!-- 每一个都遍历一次，遇到非删除值就将非删除值写到前一个排序位上，时间复杂度为O(n) -->
       
        -->

    <!-- 对比下逐个移位法更好 -->




    <!-- 在删除很多元素时： -->




    <!-- 1.逐个移位：

      <!-- 遇到第一个删除值时，就要进行移位，

      移位后需要从顺序表的第一个位置重新开始遍历（因为移位后应该是从改位置后继续遍历的）
      
      
      
      ，时间复杂度为：O(n)-->
      
       -->


       <!-- 2.结果法： -->

       <!-- 只需要遍历一次，在遍历的过程中，当遍历的值不等于被删除值时，用一个对象（k）记录（加一的形式）（为最后得到最终结果的顺序表的长度记录做准备）

      在记录到该值时，可以将该记录移到它相应的位置上
      
      （如L->data[0]，该位置肯定在当前遍历的位置上或者之前，而且由于只遍历一次的缘故，允许修改）

      遍历完一次之后，将获得的k值（非删除值，即最终结果时的顺序表的长度值）赋给L->length


      完成！！
       
      
       
       
       
       
        -->




        <!-- T5.c启示 -->

        <!-- 
        
         1.结果法中记录不在范围内的个数(即为删除后顺序表中的个数or长度)：

         当遇到不在范围内的元素时，计数变量要＋1（k++）

         并且将该元素放到最终位置上，即k-1的位置上。(L->data[k-1] = L->data[i])

         最后再更新顺序表的长度即可(L->length = k);
        
         -->

         <!-- 
         
         
        结果法中的记录在范围内的元素

        按顺序遍历时，需要先看在范围内的元素，遇到则计数元素+1(k++)

        如果遇到不在范围内的元素，则让它直接到达最终位置

        方法：找到最终位置，并赋值给它(由于只遍历一次，因此可以改变遍历过的位置的值)

        此时，最终位置应该在当前位置的前k个上（因为前面要删除k个在范围内的元素）（即L->data[i-k]=L->data[i]）

        最后再更新下顺序表的长度即可(L->length = L->length - k) 
        
        -->


        <!-- T6.c启示 -->

        <!-- 
        
        
        注意事项，移位要考虑到每一位

        这里不小心忽略了最后一位

        当对比的两个元素相同的时候，相同位计数变量加一(k++)

        当不相同时，将后一位移动到最终位置上(L->data[(i +1)- k] = L->data[i+1];)
    
        最后再处理一下顺序表的长度(L->length = L->length - k;)
        
        
        
         -->

         <!-- T7.c启示 -->



         <!-- while循环可以和for循环相互转换：
         
         
         for(int i = 0;i<L->length;i++)
         {




           code




         }


         等价于

         int i = 0;

         while(i<L->length)
         {

           
           code



           i++;
         }
         


        当满足某个条件的时候就不比较了，用for循环已经无法准确或简单地表达出

        想表达的意思了

        因此使用while，当条件满足时，一直循环执行





        当L1->data[i]>L2->data[j]时,将L2->data[j]插入到L3中

        将比较的位数加一（j++）

        否则的话，就将L1->data[i]插入到L3中

        并将比较的位数加一（i++）

        非此即彼，使用if..else..：

        if(L1->data[i]>L2->data[j])
                {
                    ListInsertLastLocation(L3, k, L2->data[j]);

                    k++;

                    j++;
                }else
                {
                   ListInsertLastLocation(L3, k, L1->data[i]);

                    k++;

                    i++;
                }





        重复上面的操作，直至i或者j有一个越界

        就结束 while (i<=((L1->length)-1) && j<=((L2->length)-1))
         
         
         
         
         
         
         
         
          -->
