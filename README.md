# Sokoban Game - Trò chơi đẩy thùng
## Giới thiệu
- Sokoban là một tựa game thuộc thể loại giải đố cổ điển, được thiết kế bởi Hiroyuki Imabayashi và được cho ra mắt vào tháng 12 năm 1982.

## Lối chơi
- Trò chơi có dạng bảng ô vuông. Có một số khối vuông (hay còn gọi là thùng) được đẩy đến đích (số ô đích đúng bằng số khối vuông). Chỉ có thể đẩy từng thùng một, và không thể kéo, cũng như không thể đẩy một dãy hai hay nhiều thùng cạnh nhau.

- Thùng bị dính tường nếu như nó bị đẩy sát vào tường mà hai bên tường đều là góc. Vì không thể kéo thùng lại được nên coi như khối này bị mất, nó không thể được đưa đến đích trừ phi đích nằm đúng trên cạnh tường đó. Dính tường là một trường hợp cần tránh khi chơi.

## Hướng dẫn chơi
- Sử dụng nút mũi tên để di chuyển nhân vật, đẩy thùng tới chỗ có đồng tiền vàng
- Khi tất cả các thùng vào hết các vị trí đồng tiền vàng thì bạn thắng
- <i>Lưu ý : </i> Khi có 1 thùng nằm ở góc hay 2 thùng cạnh nhau và sát tường mà bạn không thể di chuyển được thùng đó có nghĩa là bạn thua</br>
    Ví dụ : </br>
    </br>
![image1](https://user-images.githubusercontent.com/112875574/230716475-a8fc1019-4801-4941-8cc4-ecf40327b72e.png)
## Công nghệ sử dụng
- Game được code bằng C++ và sử dụng thư viện SDL.
## Hướng dẫn cài đặt
- <b>Bước 1 :</b> Truy cập link github : [github](https://github.com/ptdat46/Sokoban.git). Tải về dưới dạng Zip.

![image2](https://user-images.githubusercontent.com/112875574/230716914-1c8eee33-ac22-4455-a349-e0081d0e8596.png)
</br>
Sau khi tải xong, giải nén file zip này và truy cập folder vừa giải nén.
</br>
- <b>Bước 2 :</b> Nháy chuột phải vào file main.cpp, chọn Open with sau đó chọn Code::Blocks IDE (Bạn cần cài đặt CodeBlock trước khi thực hiện bước này. Bạn có thể tải về tại đây : [CodeBlock cho Microsoft](https://www.fosshub.com/Code-Blocks.html?dwl=codeblocks-20.03-setup.exe) hoặc [Codeblock cho Mac](https://www.fosshub.com/Code-Blocks.html?dwl=CodeBlocks-13.12-mac.zip)).

![](https://user-images.githubusercontent.com/112875574/230717289-5b6af770-b65e-42b7-b1a5-e9455871ce1a.png)
</br>
- <b>Bước 3 :</b> Tải và cài đặt các thư viện SDL vào CodeBlocks

[Thư viện SDL](https://drive.google.com/drive/folders/1XurDRRsGGO0jrWO-jGiGufDuqL3kHdXv?usp=sharing)<br>
[Thư viện SDL Image](https://drive.google.com/drive/folders/17jmCScYU34SX4DgE-dJR6h4dc52j-NCH?usp=sharing)<br>
[Video hướng dẫn cài SDL vào CodeBlocks](https://www.youtube.com/watch?v=dC77R3MYjcU)
</br>
- <b>Bước 4 :</b> Nháy nút Build and Run ở CodeBlocks để bắt đầu trò chơi.<br>
![](https://user-images.githubusercontent.com/112875574/230722451-56aeaf8a-9564-4be7-942f-50d26b9a225f.png)

## Cảm ơn mọi người đã quan tâm tới project của mình.<img src= "https://user-images.githubusercontent.com/112875574/230720761-49a9feb6-8580-4184-a256-9d07c0db68d5.png" width = 13px><img src= "https://user-images.githubusercontent.com/112875574/230720761-49a9feb6-8580-4184-a256-9d07c0db68d5.png" width = 13px>
