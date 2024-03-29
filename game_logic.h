#ifndef HWO_GAME_LOGIC_H
#define HWO_GAME_LOGIC_H

#include <string>
#include <vector>
#include <map>
#include <functional>
#include <iostream>
#include <jsoncons/json.hpp>

class game_logic
{
public:
	typedef std::vector<jsoncons::json> msg_vector;

	game_logic();
	msg_vector react(const jsoncons::json& msg);

private:
	typedef std::function<msg_vector(game_logic*, const jsoncons::json&)> action_fun;
	const std::map<std::string, action_fun> action_map;

	msg_vector on_game_init(const jsoncons::json& data);
	msg_vector on_ping(const jsoncons::json& data);

	msg_vector get_action();
};

#endif