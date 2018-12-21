// start.js

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

  /*radioChange: function (e) {
    //保存报警规则到当前页面的数据
    if (e.detail.value != "") {
      this.setData({
        rule: e.detail.value
      })
    }
    console.log(this.data.rule)
  },

  send: function(){
    var that = this
     //取得门限数据和报警规则
     var thres = this.data.threshold
     var Rule = this.data.rule
     
     //调用百度天气API

    const requestTask = wx.request({
      url: 'https://api.map.baidu.com/telematics/v3/weather?location=%E5%8C%97%E4%BA%AC&output=json&ak=ADfFfM3xT0jObGlOLRP3qlABiZibQrEd', //百度天气API
      header: {
        'content-type': 'application/json',
      },

      success: function (res) {
        // 利用正则字符串从百度天气API的返回数据中截出今天的温度数据
        var str = res.data.results[0].weather_data[0].date;
        var tmp1 = str.match(/实时.+/);
        var tmp2 = tmp1[0].substring(3, tmp1[0].length - 2);
        var tmp = +tmp2;

	//温度高于设置的门限值
        if (tmp > that.data.threshold) {
          if (that.data.rule == "up") { 
	    //规则为高于门限报警，于是报警
            wx.showModal({
              title: '警报！',
              content: '温度异常！',
              success: function (res) {
                if (res.confirm) {
                  console.log('用户点击确定')
                } else if (res.cancel) {
                  console.log('用户点击取消')
                }
              }
            })
          }
	   //规则为低于门限报警，于是不报警
          else if (that.data.rule == "down") {
            wx.showModal({
              title: '提示～',
              content: '温度处于正常范围。',
              success: function (res) {
                if (res.confirm) {
                  console.log('用户点击确定')
                } else if (res.cancel) {
                  console.log('用户点击取消')
                }
              }
            })
          }
        }
	//温度低于设置的门限值
        else if (tmp <= that.data.threshold) {
	 //规则为高于门限报警，于是不报警
          if (that.data.rule == "up") {
            wx.showModal({
              title: '提示～',
              content: '温度处于正常范围。',
              success: function (res) {
                if (res.confirm) {
                  console.log('用户点击确定')
                } else if (res.cancel) {
                  console.log('用户点击取消')
                }
              }
            })
          }
           //规则为低于门限报警，于是报警
          else if (that.data.rule == "down"){
            wx.showModal({
              title: '警报！',
              content: '温度异常！',
              success: function (res) {
                if (res.confirm) {
                  console.log('用户点击确定')
                } else if (res.cancel) {
                  console.log('用户点击取消')
                }
              }
            })
          }
        }
      },

      fail: function (res) {
        console.log("fail!!!")
      },

      complete: function (res) {
        console.log("end")
      }
    })
  },
  */
  //跳转到图片识别的口令验证页面
  validate: function() {
    wx.navigateTo({
      url: '../wifi_station/index/index',
    })
  },


  change: function (e) {
    //当有输入时激活发送按钮，无输入则禁用按钮
    if (e.detail.value != "") {
      this.setData({
        threshold: e.detail.value,
        opacity: 1,
        disabled: false,
      })
    } else {
      this.setData({
        threshold: 0,
        opacity: 0.4,
        disabled: true,
      })
    }
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
  
  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
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
  
  

  