# @title Hàm phủ mệnh đè
def phu(x):
    if x[0] == '-':                         # Ví dụ:input: a => output: -a
        return x[1:]                        # Ví dụ:input: -a => output: a
    else:
        return '-' + x

# @title Hàm res(x, y)
def res(x, y):
    check = False                  # Tạo biến check. Kiểm tra xem x với y có chứa 2 mệnh đề là phủ của nhau không
    ans = list(set(x + y))         # Dùng set để loại bỏ phần tử giống nhau và dùng list để convert lại kiểu list
    for i in ans[:]:               # Kiểm tra trong tập ans
        if phu(i) in ans:          # Nếu a và -a cùng tồn tại trong ans
            ans.remove(i)          # Thì loại bỏ chúng
            ans.remove(phu(i))
            check = True           # Nếu trong ans chứa cả a và -a thì gán check = True
    return sorted(ans), check


# hàm robinson
# @title Hàm Ronbison
def robinson(TAP):
    TAP = TAP.split(",")                            # Cắt tập thành các dòng
    so = 1                                          # Biến lưu số thứ tự của dòng
    my_dict = {}                                    # Tạo 1 từ điển my_dict để lưu các dòng
    for menh_de in TAP:                             # Chia nhỏ từng phần tử thành cách quan hệ
        my_dict[so] = sorted(menh_de.split("v"))    # Cắt biểu thức và lưu dưới dạng list sắp xếp
        so += 1
    for key, val in my_dict.items():                # In ra màn hình các dòng khởi tạo
        print("{:>3}.  {}".format(key, val))
    da_duyet = set()                                                        # Tạo tập da_duyet để lưu các cặp đã kiểm tra
    i = 1
    while 1 < so:                                         # Chọn tuần tự các cặp dòng chứa trong my_dict
        for j in list(my_dict.keys())[i:]:                                  # Chọn duyệt từ dòng thứ i để tránh cặp với những dòng cũ
            if (i, j) not in da_duyet:                                      # Nếu 2 dòng chưa duyệt
                tam, check = res(my_dict[i], my_dict[j])                    # Thì tam = recuse(a, b)
                da_duyet.update({(i, j), (i, so), (j, so)})                 # Cập nhật danh sách da_duyet
                if not check:                                               # Nếu a và b không có mệnh đề phủ của nhau
                    continue                                                # Ta bỏ qua vòng lặp
                if not tam:         # Tương đương tam == []                 # Nếu dòng này là rỗng (==[])
                    print("{:>3}. Res({:>2}, {:>3}) = {}".format(so, i, j, tam))        # In ra màn hình
                    print("=> Vậy bài toán được chứng minh.")
                    return True                                             # Thì trả về True, dừng vòng lặp
                if tam not in my_dict.values():                             # Nếu tam không là 1 trong các dòng đã có
                    print("{:>3}. Res({:>2}, {:>3}) = {}".format(so, i, j, tam))        # In ra màn hình
                    my_dict[so] = tam                                                   # Thêm vào my_dict
                    so += 1
    # print(da_duyet)
    return False


# @title Main
TAP = "-av-bvc,-gvd,-cvd,a,b,-d"
print(robinson(TAP))
