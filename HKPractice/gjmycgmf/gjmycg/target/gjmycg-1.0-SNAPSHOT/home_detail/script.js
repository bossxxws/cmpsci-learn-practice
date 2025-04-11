var flowers = 19 // not meant to be changed
function addFlower() {
  var f = document.createElement('div')
  f.className = 'flower'
  f.style.width = '3px'
  var num = Math.ceil(Math.random() * 15) * 5
  f.style.height = num + 'vh'
  f.style.background = 'hsl(10deg,50%,'+(Math.random() * 40 + 20)+'%)'
  f.style.position = 'fixed'
  f.style.top = 0
  f.style.left = flowers * 5 + 2.5 + '%'
  f.style.transform = 'translateY(-100%)'
  f.style.animationDelay = Math.random() * 3 + 's'
  f.style.animationDuration = num * .25 + 's'
  f.style.borderRadius = '0 0 1rem 1rem'
  f.style.pointerEvents = 'none'
  flowers--

  //leafs
  for(var i=0;i<num*.4;i++) {
    var l = document.createElement('div')
    l.className = 'leaf'
    var side = Math.random() < .5 ? 'transform:scaleX(-1);' : '',
        show = Math.random() < .5 ? 'hidden' : '',
        color = 'hsl(150deg,50%,'+(Math.random() * 40 + 20)+'%)'
    f.innerHTML += `<div class='leaf_box' style='width:3vh;height:2.5vh;background:${color};display:block;visibility:${show};border-radius:0% 75% 0% 75%;transform-origin:1.5px 50%;${side}'></div>`
  }

  document.body.appendChild(f)
}

function buildWorld(){
  flowers = 19
  for(var i=0;i<20;i++) {
    addFlower()
  }
}
buildWorld()


buildWorld()
