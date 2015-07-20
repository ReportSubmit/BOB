<IMG SRC="copy_compare_cmd.png">
<IMG SRC="copy_compare_file.png">

파일을 Copy하는 시간을 확인해보면 mmio가 빠른것을 확인할 수 있습니다.

<IMG SRC="create_big_file.png">
오류가 나는 이유는 MemoryOfView Function 에서 4G가 이상의 파일의 메모리를 올릴 수 없게 되어있습니다.
그 이유는 int32 를 쓰기 때문입니다. 그래서 32비트 즉 3.99G만 올라가게 됩니다.
그래서 FileCreate 로 0byte 의 파일 틀을 생성하고 WriteToFile 함수의 offset을 이용하여
다음 그림과 같이 5G가의 파일을 생성하였습니다.
