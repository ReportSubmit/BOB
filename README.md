<IMG SRC="https://github.com/ReportSubmit/OS_HW2/raw/master/copy_compare_cmd.PNG" alt="alt tag">
<IMG SRC="https://github.com/ReportSubmit/OS_HW2/raw/master/copy_compare_file.PNG" alt="alt tag">

파일을 Copy하는 시간을 확인해보면 mmio가 빠른것을 확인할 수 있습니다.

<IMG SRC="https://github.com/ReportSubmit/OS_HW2/raw/master/create_big_file.PNG" alt="alt tag">
오류가 나는 이유는 MemoryOfView Function 에서 4G가 이상의 파일의 메모리를 올릴 수 없게 되어있습니다.
그 이유는 int32 를 쓰기 때문입니다. 그래서 32비트 즉 3.99G만 올라가게 됩니다.
그래서 FileCreate 로 0byte 의 파일 틀을 생성하고 WriteToFile 함수의 offset을 이용하여
다음 그림과 같이 5G가의 파일을 생성하였습니다.
