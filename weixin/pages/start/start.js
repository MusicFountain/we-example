Page({

  /**
   * 页面的初始数据
   */
  data: {
    audioPoster: 'http://y.gtimg.cn/music/photo_new/T002R300x300M000003rsKF44GyaSk.jpg?max_age=2592000',
    audioName: '此时此刻',
    audioAuthor: '许巍',
    audioSrc: 'http://ws.stream.qqmusic.qq.com/M500001VfvsJ21xFqb.mp3?guid=ffffffff82def4af4b12b3cd9337d5e7&uin=346897220&vkey=6292F51E1E384E06DCBDC9AB7C49FD713D632D313AC4858BACB8DDD29067D3C601481D36E62053BF8DFEAF74C0A5CCFADD6471160CAF3E6A&fromtag=46',
    imageSrc: '../../pages/image/hj1.jpg',
  },


  validate: function() {
    wx.navigateTo({
      url: '../wifi_station/index/index',
    })
  },
  onReady: function () {

    this.animation = wx.createAnimation({
      duration: 1000, // 动画持续时间为1000ms
      timingFunction: 'linear', //动画效果
      delay: 100, // 延迟多长时间开始
      transformOrigin: '50% 50% 0',  //设置基点为图片中心
      success: function (res) {
        console.log(res)
      }
    })
  },

  /**
   * 旋转
   */
  rotate: function () {
    this.setData({
      animation: this.animation.export()
    })
    var n = 0;
    //连续动画需要添加定时器,所传参数每次+1
    setInterval(function () {
      // animation.translateY(-60).step()
      n = n + 1;
      console.log(n);
      this.animation.rotate(15 * (n)).step()  //每次旋转15度
      this.setData({
        animation: this.animation.export()
      })
    }.bind(this), 1000) //1000为周期性执行或调用code之间的时间间隔，以毫秒计
  },

 
    onShow: function () {
      // 页面显示

    },
    onHide: function () {
      // 页面隐藏
    },
    onUnload: function () {
      // 页面关闭
    }
  })
  
  

  
  
  

  
