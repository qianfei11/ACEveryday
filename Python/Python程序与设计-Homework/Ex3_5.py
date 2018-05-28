class Listinfo(object):
    def __init__(self, args=[]):
        self.my_list = args
    def add_elem(self, elename):
        self.my_list.append(elename)
    def get_elem(self, num):
        return self.my_list[num]
    def merge_list(self, ls):
        self.my_list.extend(ls)
    def del_lastone(self):
        self.my_list.pop(len(self.my_list) - 1)

if __name__ == '__main__':
    list_info = Listinfo([44, 222, 111, 333, 454, 'sss', '333'])
    print(list_info.my_list)
    list_info.add_elem('string')
    print(list_info.my_list)
    list_info.add_elem(123)
    print(list_info.my_list)
    x = list_info.get_elem(4)
    print(x)
    list_info.merge_list([1, 2, 3, 'a'])
    print(list_info.my_list)
    list_info.del_lastone()
    print(list_info.my_list)