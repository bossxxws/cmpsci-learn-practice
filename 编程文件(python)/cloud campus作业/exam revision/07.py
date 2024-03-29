class Song:
    def __init__(self,title,art,length):
        self.title=title
        self.artist=art
        self.song_length=length
    def __str__(self):
        li=self.song_length.split(":")
        time=int(li[0])*60+int(li[1])
        return f'"{self.title}" by {self.artist}({time})'
class Album:
    def __init__(self,name) -> None:
        self.name=name
        self.song_list=[]
        self.num=0
    def add_song(self,ele):
        self.song_list.append(ele)
        self.num+=1
    def __str__(self) -> str:
        if self.num==0:
            return f"{self.name}:\nThe list is empty!"
        else:
            res=""
            for i in range(0,self.num):
                res+=str(self.song_list[i])+"\n"
            res=res[:-1]
            return f"{self.name}:\n{res}"
    def get_total_song_lengths(self):
        to=0
        for i in range(0,self.num):
            li=self.song_list[i].song_length.split(":")
            time=int(li[0])*60+int(li[1])
            to+=time
        return to
    def remove_songs_by_artist(self, artist):
        for i in range(0,self.num):
            if self.song_list[i].artist==artist:
                del self.song_list[i]
                self.num-=1
album = Album("My own Album")
s1 = Song('Bloom','Radiohead',"5:15")
s2 = Song('Morning Mr Magpie','Radiohead','4:41')
album.add_song(s1)
album.add_song(s2)
print(album)
print(album.get_total_song_lengths())
print(type(album))
	
my_own_album = Album("My own Album")
print(my_own_album)

album1 = Album("Album 1")
songs = [Song('Separator', 'Radiohead','5:20'), Song('Sour Times', 'Portishead', '4:11'), Song('Morning Mr Magpie','Radiohead','4:41'), Song('Bloom','Radiohead',"5:15")]
for s in songs:
    album1.add_song(s)
print(album1)
print(album1.get_total_song_lengths())

