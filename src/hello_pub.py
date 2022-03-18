#!/usr/bin/env python3
# 1번 라인은 명령어이므로 반드시 달아줘야 한다

import rospy				# ROS 라이브러리
from ngu_pkg.msg import test_msg	# 패키지의 메시지 파일

def main():
    # 퍼블리시 노드 초기화
    ## 노드 이름 talker
    rospy.init_node('talker', anonymous=True)
    
    # 퍼블리셔 변수
    ## 퍼블리시 토픽 이름 chatter, 메시지 타입 test_msg
    pub = rospy.Publisher('chatter', test_msg, queue_size=10)
    
    # 10헤르츠마다 반복(변수=rate)
    rate = rospy.Rate(10) # 10hz

    msg = test_msg()	# 메시지 변수 선언
    count = 0		# 코드에서 사용할 변수 선언

    # 중단되거나 사용자가 강제종료(ctrl+C) 전까지 계속 실행
    while not rospy.is_shutdown():
        msg.stamp = rospy.Time.now()	#현재 시각 담음
        msg.data = count		# count 변수 값 담음

        # 터미널에 출력
        rospy.loginfo("send time(sec) = %d", msg.stamp.secs)
        rospy.loginfo("send msg = %d", msg.data)
        rospy.loginfo("Hello?")
        
        # 메시지를 퍼블리시
        pub.publish(msg)
        
        # 정해둔 주기(hz)만큼 일시중단
        rate.sleep()

        count += 1

if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass