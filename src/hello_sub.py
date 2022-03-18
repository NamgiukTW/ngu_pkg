#!/usr/bin/env python3
# 1번 라인은 명령어이므로 반드시 달아줘야 한다

import rospy
from ngu_pkg.msg import test_msg

# 퍼블리셔 노드로부터 토픽을 받아들이는 콜백 함수
def callback(data):
    # 받은 내용(data)를 터미널에 출력
    rospy.loginfo("recieve time(sec) = %d", data.stamp.secs)
    rospy.loginfo("recieve msg = %d", data.data)
    rospy.loginfo("Hello World!!")
    
def main():
    # 노드 초기화. 이름은 listener
    rospy.init_node('listener', anonymous=True)

    # 특정 토픽(chatter)를 callback이라는 이름의 함수로 받아들이며, 메시지 타입은 test_msg
    rospy.Subscriber("chatter", test_msg, callback)

    rospy.spin()

if __name__ == '__main__':
    main()