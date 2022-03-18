#include "ros/ros.h"
#include "ngu_pkg/test_msg.h" // (자신의 패키지 이름/메시지 헤더파일) 빌드를 한번 실행해야 오류 메시지가 사라짐

// 메시지 콜백 함수 선언
//// 처리할 메시지를 포인터로서 파라미터로 전달. 포인터의 자료형은 메시지의 타입을 명시
void chatterCallback(const ngu_pkg::test_msg::ConstPtr& msg)
{
  ROS_INFO("recieve time(sec) = %d", msg->stamp.sec);
  ROS_INFO("recieve msg = %d", msg->data);
  ROS_INFO("hello world!!");
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "hello_world_subnode");		// 노드 이름 초기화

  ros::NodeHandle nh;

  // 서브스크라이버 선언
  //// 토픽 이름: chatter(publish 노드에서 주는 토픽), 큐 사이즈: 100개
  //// 콜백 함수 이름: chatterCallback(위에서 정의함, 여기서 받은 토픽을 처리함)
  ros::Subscriber sub = nh.subscribe("/chatter", 100, chatterCallback);

  ros::spin();		// 큐에 요청된 콜백함수를 처리하며, 프로그램 종료시까지 반복함

  return 0;
}