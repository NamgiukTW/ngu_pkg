#include "ros/ros.h"			// ROS 기본 헤더 파일
#include "ngu_pkg/test_msg.h"		// (자신의 패키지 이름/메시지 헤더파일) 빌드를 한번 실행해야 오류 메시지가 사라짐

int main(int argc, char **argv)
{
  ros::init(argc, argv, "hello_world_pubnode");     // 노드 이름 초기화
  ros::NodeHandle nh;                  // ROS 시스템과 통신을 위한 노드 핸들
  
  // 퍼블리셔 선언
  //// ngu_pkg에 정의된 test_msg 메시지 메시지 파일을 이용함
  //// 만약 표준 메시지를 사용한다면 그에 맞게 사용해야 함. (예) <std_msgs::String>
  //// 토픽 이름: chatter, 큐 사이즈: 100개
  ros::Publisher chatter_pub = nh.advertise<ngu_pkg::test_msg>("/chatter", 100);

  // 루프 주기를 10hz로 설정. 1초에 10번 루프를 돌며 메시지를 송신함.
  ros::Rate loop_rate(10);


  ngu_pkg::test_msg msg;		// 메시지 변수 선언
  int count = 0;			// 코드 내에서 사용할 변수 선언

  while (ros::ok())			// 종료 전까지 계속 반복 수행함
  {
    msg.stamp = ros::Time::now();	// 메시지 내 stamp 메시지에 현 시각 입력
    msg.data  = count;			// 메시지 내 data 메시지에 count 변수값 입력

    ROS_INFO("send time(sec) = %d", msg.stamp.sec);
    ROS_INFO("send msg = %d", msg.data);
    ROS_INFO("hello?");

    chatter_pub.publish(msg);	// 메시지를 퍼블리시함(토픽으로 전송)

    loop_rate.sleep();		// 정해준 주기만큼 일시정지(sleep)

    ++count;
  }

  return 0;
}