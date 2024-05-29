# Blackjack
# Mục lục
- [0. Cài đặt](#0-cài-đặt)
- [1. Mô tả chung](#1-mô-tả-chung)
- [2. Hướng dẫn chơi](#2-hướng-dẫn-chơi)
- [3. Phương thức chơi](#3-phương-thức-chơi)
- [4. Hỗ trợ](#4-hỗ-trợ)
- [5. Credits](#5-credits)
# 0. Cài đặt
**Bước 1**: Clone repo này về bằng lệnh `git clone https://github.com/14m6d4/BlackJack_SDL2.git`</br>
**Bước 2**: Tải IDE Visual Studio tại [đây](https://visualstudio.microsoft.com). Các bạn tải về bản Community 2022.</br>
**Bước 3**: Cài đặt thư viện `SDL2` tại [đây](https://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/msvc2019/index.php). Áp dụng tương tự với các thư viện mở rộng như `SDL2_image`, `SDL2_ttf`,`SDL2_mixer`.</br>
**Bước 4**: Khởi động file `BlackJackSDL.sln`, sau đó chạy biên dịch và tận hưởng game!
# 1. Mô tả chung
Blackjack, còn được gọi là 21, là một trò chơi bài phổ biến tại các sòng bạc, nơi người chơi cạnh tranh với nhà cái thay vì với nhau. Trò chơi mang lại sự kịch tính với những chiến thuật đơn giản nhưng sâu sắc, khiến nó trở thành một trong những trò chơi bài được yêu thích nhất trên thế giới.
# 2. Hướng dẫn chơi
>Video demo game: https://drive.google.com/file/d/1L0tOmrOI29cWfNMtyAp8QZLHrfALdXkz/view?usp=sharing

Để chiến thắng trò chơi, bạn cần phải có tổng giá trị các quân bài cao hơn người chia bài và không được vượt quá 21. Trò chơi sử dụng bộ bài tiêu chuẩn 52 lá. Người chơi và nhà cái sẽ nhận hai lá bài ban đầu; lá bài của người chơi sẽ được lật ngửa, còn nhà cái có một lá úp và một lá ngửa. Người chơi có hai tuỳ chọn là rút thêm bài (Hit) hoặc dừng lại (Stand).

Giá trị lá bài:
- Các lá bài số (2-10): có giá trị tương đương với số trên lá bài.
- Các lá bài hình (J, Q, K): có giá trị 10 điểm.
- Lá Át (A): có thể tính là 1 hoặc 11 điểm, tuỳ theo giá trị nào có lợi hơn cho người chơi.

Quá trình chơi:
1. Bắt đầu ván chơi mới, người chơi sẽ có sẵn $1000 đô trong túi.
2. Với lượt đầu của mỗi vòng chơi, người chơi tiến hành đặt cược bằng cách nhấn nút (+) hoặc (-) để tăng hoặc giảm tiền cược rồi nhấn vào nút tiền cược để xác nhận và bắt đầu lượt chơi.
3. Người chơi sử dụng phím Hit để rút thêm bài hoặc Stand để dừng lại rồi so bài với người chia bài.
4. Nếu người chơi thắng thì tiền thưởng sẽ được cộng vào số tiền gốc. Ngược lại, nếu thua sẽ bị trừ tiền.

Người chơi có quyền chơi qua nhiều vòng đấu cho tới khi số tiền trong túi về $0. Lúc đó, nếu muốn chơi tiếp, người chơi sẽ phải chơi ván mới và bắt đầu lại với $1000 đô.
# 3. Phương thức chơi
Người chơi sử dụng chuột nhấn vào các phím tương ứng trên màn hình để chơi game.
# 4. Hỗ trợ
Nếu có bất kỳ thắc mắc nào trong quá trình chơi, hãy liên lạc qua mail: tiendat.workspace@gmail.com. Mình sẽ cố gắng phản hồi trong thời gian sớm nhất có thể.
# 5. Credits
- Thầy Lê Quang Hiếu: vì những bài giảng đã giúp em có nền móng để bắt đầu làm game.
- Thầy Ngô Xuân Trường: vì những góp ý đã giúp em có thể hoàn thiện game.
- https://wiki.libsdl.org/SDL2/FrontPage
- https://www.willusher.io/pages/sdl2/
- https://lazyfoo.net/tutorials/SDL/
- [Tài liệu bổ sung](https://docs.google.com/document/d/1FZ3jTqHxtyZznNWiJmmve0zYu_aSliUqLP2OsMcdehQ/edit?tab=t.0#heading=h.n8fowkm18xov) của TS. Trần Thị Minh Châu.
