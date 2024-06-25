class Song:
    def __init__(self,title,art,length):
        self.title=title
        self.artist=art
        self.song_length=length
    def __str__(self):
        li=self.song_length.split(":")
        time=int(li[0])*60+int(li[1])
        return f'"{self.title}" by {self.artist}({time})'
song1 = Song('Bloom','Radiohead',"5:15")
print(song1)
print(type(song1))