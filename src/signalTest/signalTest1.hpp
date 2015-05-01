/*
 * signalTest1.hpp
 *
 *  Created on: May 1, 2015
 *      Author: vermosen
 */

#ifndef SIGNALTEST1_HPP_
#define SIGNALTEST1_HPP_

#include <thOth/types.hpp>
#include <thOth/pattern/observer2.hpp>
#include <thOth/pattern/observable2.hpp>

#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>

// a sender
void sendingLoopInt(int seed, thOth::observable2<thOth::real> & send) {

	for (int i = seed;; i++) send(i);

};

void signalTest1() {

	thOth::observable2<thOth::real> send;
	thOth::observer2<thOth::real> rec;

	std::cout << "this thread id: " << boost::this_thread::get_id();

	send.registerWith(rec);

	// create the sender threads
	boost::thread sendingThread1(sendingLoopInt, 1,   boost::ref(send));
	boost::thread sendingThread2(sendingLoopInt, 100, boost::ref(send));

	// join the threads
	sendingThread1.join();
	sendingThread2.join();

}

#endif /* SIGNALTEST1_HPP_ */
