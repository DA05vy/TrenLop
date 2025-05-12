# @title Hàm phủ trả về logic phủ
def phu(x):                       # Hàm này trả về logic phủ của logic
    tam = x.copy()                # Lấy bản sao của biến x, tránh thay đổi trực tiếp biến đầu vào
    if tam[0][0] == '-':          # Ví dụ:input: a(x, y) => output: -a(x, y)
        tam[0] = tam[0][1:]       # Ví dụ:input: -a(x, y) => output: a(x, y)
    else:
        tam[0] = '-' + tam[0]
    return tam


# @title Hàm đổi biến
def doibien(tap_vitu, tap_doi):                     # Hàm này có tác dụng đổi biến của một tập logic vị từ
    tap_vitu_new = []                               # Tạo list chứa tập logic sau khi đổi biến
    for vitu in tap_vitu:                           # Xét từng logic
        vitu_new = [vitu[0], vitu[1][:]]            # Tạo logic bản sao
        for i in range(len(vitu[1])):               # Xét từng biến trong logic
            for j in range(len(tap_doi)):           # Xét từng cặp giá trị trong tập đổi
                if tap_doi[j][0] == vitu[1][i]:     # Nếu biến này cần đổi
                    vitu_new[1][i] = tap_doi[j][1]  # Thì đổi thành giá trị tương ứng
        tap_vitu_new.append(vitu_new)               # Thêm logic mới vào tập
    return tap_vitu_new                             # Trả về tập logic đã thay đổi

    # Ta có ví dụ sau: tap_vitu = [['-P', ['x', 'y']], ['-P', ['y', 'z']]] và tap_doi = [['x', 'hoa'], ['y', 'cây']]
    # Tức là ta cần: thay biến 'x' thành giá trị 'hoa'
    #                     biến 'y' thành giá trị 'cây'
    # Ta sẽ thu được kết quả là: ap_vitu_new = [['-P', ['hoa', 'cây']], ['-P', ['cây', 'z']]]


# @title Hàm res trả về res(a, b) (tiếp)
def res(a, b, bien, giaTri):                # Viết hàm để rescuse a và b
    ans = []                                # Tạo biến ans
    for i in a:                             # Xét từng logic trong a
        if i not in ans:                    # Nếu logic chưa có trong a
            ans.append(i)                   # Thì thêm vào ans, tránh trùng lặp
    check = False                           # Tạo biến check. Kiểm tra xem a với b có chứa 2 logic là phủ của nhau không
    for i in b:                             # Xét từng logic có trong b
        if i in ans:                        # Nếu i trong ans
            continue                        # Bỏ qua vòng lặp
        tam = phu(i)                        # Lấy phủ của logic vị từ đó
        if tam in ans:                      # Nếu logic phủ của i có trong ans
            ans.remove(tam)                 # Thì xóa logic phủ của i trong ans
            check = True                    # gán check = True
        else:                                     # Nếu không
            ans.append(i)                         # Thêm i vào ans
        # print('ans = ', ans, check)
    if check:                               # Nếu res có thể loại bỏ được ít nhất 1 cặp logic
        return sorted(ans), None            # Trả về tập ans và None
    tap_ketqua = []                               # Tập lưu trữ kết quả
    tap_doi = []                                  # Tập lưu trữ các cặp đổi
    vitu_chon = []                                # Tập lưu trữ các logic chọn
    for i in ans:                                 # Duyệt từng phần tử trong ans
        for j in i[1]:                            # Kiểm tra phần biến của logic vị từ
            if j in giaTri:                       # Nếu xuất hiện 1 giá trị
                vitu_chon.append(i)               # Thêm vào vitu_chon
                break                             # Bỏ qua các biến khác của vị từ đang xét
    # print('vitu_chon = ', vitu_chon)      # Tức là ở đây ta ưu tiên chọn các vị từ đã có sẵn giá trị như: ['P', ['x', 'cothe']]
                                            # Với 'x' là biến, 'cothe' là giá trị
    for i in vitu_chon:                                         # Lấy từng vị từ chọn
        hang_doi = []                                           # Tạo hàng đợi
        for j in ans:                                           # Duyệt từng phần tử trong ans
            if i[0] == '-' + j[0] or '-' + i[0] == j[0]:        # Nếu vị từ đó trái dấu với vị từ đang xét: Tăng khả năng có thể res. Ví dụ -chame(...) có thể res được với chame(...)
                check = True                                    # Tạo biến check để kiểm tra khả năng có thể res với vị từ đang xét
                for k in range(len(j[1])):                      # Duyệt từng biến trong vị từ
                    if ((j[1][k] in giaTri and i[1][k] in giaTri) or (j[1][k] in bien and i[1][k] in bien)) and j[1][k] != i[1][k]:
                        check = False                           # Nếu các cặp biến tương ứng đều nằm trong tập giá trị hoặc biến và khác nhau
                        break                                   # Thì gán False. Vì 2 vị từ này không thể là phủ của nhau
                                                                # Ví dụ: ['P', ['x', 'cothe']] và ['P', ['y', 'tay']]
                                                                # 'cothe' và 'tay' đều là giá trị và khác nhau. Nên chúng không thể phủ của nhau
                if check:                                       # Nếu check = True
                    hang_doi.append(j)                          # Thêm vào hàng đợi
        # print('i = ', i); print('hang_doi =', hang_doi)
        for j in hang_doi:                                            # Kiểm tra từng phần tử trong hàng đợi
            # print('j = ', j); print('i = ', i)
            doi = []                                                  # Tạo tập đổi
            da_the = []                                               # Tạo tập đã thế.
            for k in range(len(j[1])):                                # Duyệt từng cặp biến tương ứng của vị từ chọn và vị từ hàng đợi
                if i[1][k] in giaTri and j[1][k] not in giaTri and j[1][k] not in da_the:# Nếu biến vị từ chọn là giá trị và biến vị từ đợi không là giá trị và biến này chưa được thế
                    doi.append([j[1][k], i[1][k]])                    # Tạo 1 cặp thế ví dụ ['x', 'hoa'] thể hiện biến 'x' cần thay bằng giá trị 'hoa'
                    da_the.append(j[1][k])                            # Thêm biến thế vào tập đã thế
                elif i[1][k] not in giaTri and j[1][k] in giaTri and i[1][k] not in da_the:    # Nếu biến vị từ chọn và vị từ đợi khác nhau và chưa được thế
                    doi.append([i[1][k], j[1][k]])                            # Ví dụ: xét 2 vị từ ['P', ['x', 'cothe', 'z']] và ['P', ['tay', 'y', 'z']]
                    da_the.append(i[1][k])                                    # Ta sẽ thu được doi = [['x', 'tay'], ['y', 'cothe']]
                                                                      # Tập da_the sử dụng khi ta xét: ['P', ['x', 'cothe']] và ['P', ['tay', 'x']]
                                                                      # Khi 'x' thay bằng 'tay' rồi thì sẽ không thay bằng 'cothe' nua
            a_new = doibien(a, doi)                                   # Đổi biến cho tập a với tập đổi vừa tìm được
            b_new = doibien(b, doi)                                   # Đổi biến cho tập b
            # print('a = ', a); print('doi = ', doi); print('a_new = ', a_new)
            tmp1, tmp2 = res(a_new, b_new, bien, giaTri)              # res a và b sau khi đã đổi biến
            # print('tmp1 = ', tmp1)
            tap_ketqua.append(sorted(tmp1))                           # Thêm tập logic đã được sắp xếp vào tập kết quả
            tap_doi.append(doi)                                       # Thêm đổi vào tập kết quả
    return tap_ketqua, tap_doi


# @title Hàm tạo logic vị từ
def tao_vitu(tap_vitu):
    tam = []                                   # Tạo tập tạm lưu trữ
    for i in range(len(tap_vitu)):
        a = (', ').join(tap_vitu[i][1])        # Nối các biến lại
        a = tap_vitu[i][0] + '(' + a +')'      # Ghép thành 1 logic vị từ
        tam.append(a)                          # Thêm vào tạm
    # print('tam = ', tam); print('tap_vitu = ', tap_vitu)
    tam = (' v ').join(tam)                    # Nối các logic vị từ bởi dấu v
    return tam


# @title Hàm tạo phép thế
def tao_phepthe(doi):
    tam = doi.copy()                          # Lấy bản sao của tập đổi
    for i in range(len(tam)):
        tam[i] = (' = ').join(tam[i])         # Nối lại x = An
        # print(tam2)
    tam = (', ').join(tam)                    # Nối các phép thế lại x = An, y = Bình
    return tam


# @title Hàm robinson (tiếp)
def robinson(TAP, bien, giaTri):            # Thuật giải Robinson, input là các dòng, tập biến và tập giá trị
    so = 1                                  # Biến lưu số thứ tự của dòng
    my_dict = {}                            # Tạo 1 từ điển my_dict để lưu các dòng
    for vitu in TAP:
        my_dict[so] = vitu                  # Thêm vị từ vào my_dict
        so += 1

    for key, val in my_dict.items():                        # In ra màn hình các dòng khởi tạo
        print("{:>3}. {}".format(key, tao_vitu(val)))

    da_duyet = set()                        # Tạo tập da_duyet để lưu các cặp đã kiểm tra
    i = 1                                   # Biến i là dòng đang xét
    while i < so:                           # Nếu dòng i trong my_dict
        for j in list(my_dict.keys())[i:]:                                  # Chọn duyệt lần lượt từ dòng thứ i để tránh cặp với những dòng cũ
            if (i, j) not in da_duyet:                                      # Nếu 2 dòng chưa res
                dong_moi, tap_doi = res(my_dict[i], my_dict[j], bien, giaTri)                           # Thì tam = recuse(a, b)
                # print('dong_moi = ', dong_moi); print('tap_doi = ', tap_doi)
                da_duyet.update({(i, j)})                                   # Cập nhật danh sách da_duyet
                if tap_doi is None:                                         # Nếu tap_doi là None
                    if not dong_moi:         # Tương đương dong_moi == []   # Nếu dòng này là rỗng (==[])
                        print("{:>3}. Res({:>2}, {:>3}) = {}.".format(so, i, j, '[]'))        # In ra màn hình
                        print("=> Điều phải chứng minh.")
                        return True                                         # Thì trả về True, dừng hàm
                    if dong_moi not in my_dict.values():                    # Nếu dong_moi không là 1 trong các dòng đã có
                        my_dict[so] = dong_moi                              # Thêm vào my_dict
                        print("{:>3}. Res({:>2}, {:>3}) = {}.".format(so, i, j, tao_vitu(dong_moi)))        # In ra màn hình
                        da_duyet.update({(i, so), (j, so)})                 # Cập nhật danh sách da_duyet. Vì so là dòng con của res(i, j)
                        so += 1                                             # Nên ta không cần res lại chúng
                    continue                                                # Bỏ qua phần lệnh phía dưới
                for k in range(len(dong_moi)):                              # Nếu tap_doi không là None, duyệt từng dòng trả về
                    if not dong_moi[k]:   # Tương đương dong_moi[k] == []   # Nếu dòng này là rỗng (==[])
                        print("{:>3}. Res({:>2}, {:>3}) = {}. Thế ({})".format(so, i, j, [], tao_phepthe(tap_doi[k])))     # In ra màn hình
                        print("=> Điều phải chứng minh.")
                        return True                                         # Thì trả về True, dừng hàm
                    if dong_moi[k] not in my_dict.values():                 # Nếu dong_moi[k] không là 1 trong các dòng đã có
                        my_dict[so] = dong_moi[k]                           # Thêm vào my_dict
                        print("{:>3}. Res({:>2}, {:>3}) = {}. Thế ({})".format(so, i, j, tao_vitu(dong_moi[k]), tao_phepthe(tap_doi[k]))) # In ra màn hình
                        da_duyet.update({(i, so), (j, so)})                 # Cập nhật danh sách da_duyet
                        so += 1
            # print('my_dict = ', my_dict)
        i += 1           # Duyệt dòng tiếp theo
    # print(da_duyet)
    return False


# @title Hàm xử lý đầu vào
def xuLyDauVao(dong):                                  # Hàm xử lý các dòng input
    dong = dong.replace(' ', '')                       # Xóa dấu space thừa
    dong = dong + ','                                  # Thêm dấu phẩy ở cuối.
    dong = dong.split('),')                            # Cắt các dòng
    dong = [i + ')' for i in dong][:-1]                # Hoàn thiện lại các dòng, bỏ phần tử trống ở cuối
    for i in range(len(dong)):                         # Duyệt từng dòng
        dong[i] = dong[i].split('v')                   # Cắt thành các logic vị từ
        dong[i] = [j[:-1].split('(') for j in dong[i]] # Tách riêng phần tên và phần biến của logic vị từ
        for j in range(len(dong[i])):                  # Duyệt từng logic vị từ
            dong[i][j][1] = dong[i][j][1].split(',')   # Cắt nhỏ các đối tượng trong logic vị từ
    return dong
    # Ý tưởng: Ta có input = 'a(x,y),b(x,y)'
    # Nếu ta cắt bằng dấu ',' thì kết quả trả về là ['a(x', 'y)', 'b(x', 'y)']
    # Tức là sẽ bị cắt ở cả dấu phẩy ngăn cách các biến
    # Nhận thấy logic kết thúc bằng dấu ')'
    # Nên ta thêm dấu ',' và cắt bằng '),'
    # KL = [i + ')' for i in (KL.replace(' ', '') + ',').split('),')][:-1]
    # for i in range(len(KL)):
    #     KL[i] = KL[i].split('v')
    #     KL[i] = [j[:-1].split('(') for j in KL[i]]
    #     for j in range(len(KL[i])):
    #         KL[i][j][1] = KL[i][j][1].split(',')


# @title Main
TAP = '-chame(x, y) v -chame(x, z) v anhem(y, z), -chame(x, y) v -chame(z, t) v -anhem(x, z) v anhem(y, t), -anhem(x, y) v anhem(y, x), chame(B, N), chame(T, D), chame(A, B), chame(A, T), -anhem(N, D)'
bien = ['x', 'y', 'z', 't']
giaTri = ['A', 'B', 'N', 'T', 'D']
# Chạy chương trình
TAP = xuLyDauVao(TAP)
print(TAP)
robinson(TAP, bien, giaTri)



# print(res([['-P', ['x', 'y']], ['-P', ['y', 'z']], ['P', ['x', 'z']]], [['P', ['nt', 'bt']]], ['x', 'y', 'z'], ['nt', 'bt', 'ct', 'cothe']))
# print(doibien([['-P', ['x', 'y']], ['-P', ['y', 'z']], ['P', ['x', 'z']]], [['x', 'cothe'], ['y', 'nt']]))
# print(in_manhinh(1, 1, 1, [['-P', ['x', 'y']], ['-P', ['y', 'z']], ['P', ['x', 'z']], ['P', ['nt', 'bt']]], [['x', 'nt'], ['y', 'bt']]))
# my_dict =  {1: [['-P', ['x', 'y']], ['-P', ['y', 'z']], ['P', ['x', 'z']]], 2: [['P', ['nt', 'bt']]], 3: [['P', ['bt', 'ct']]], 4: [['P', ['ct', 'cothe']]], 5: [['-P', ['nt', 'cothe']]], 6: [['-P', ['bt', 'z']], ['P', ['nt', 'z']]], 7: [['-P', ['x', 'nt']], ['P', ['x', 'bt']]], 8: [['-P', ['ct', 'z']], ['P', ['bt', 'z']]], 9: [['-P', ['x', 'bt']], ['P', ['x', 'ct']]], 10: [['-P', ['cothe', 'z']], ['P', ['ct', 'z']]], 11: [['-P', ['x', 'ct']], ['P', ['x', 'cothe']]], 12: [['-P', ['nt', 'y']], ['-P', ['y', 'cothe']]]}
# print(res([['-P', ['x', 'y']], ['-P', ['y', 'z']], ['P', ['x', 'z']]], [['-P', ['bt', 'z']]], ['x', 'y', 'z'], ['nt', 'bt', 'ct', 'cothe']))
