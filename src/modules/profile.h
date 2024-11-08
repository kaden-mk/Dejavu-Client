void initProfile()
{
	server.Post(R"(/fortnite/api/game/v2/profile/(.*)/client/(.*))", [](const Request& req, Response& res)
	{
		std::string profile_id = "common_core";
		short rvn = 0;
		json profileData;

		if (req.has_param("rvn")) rvn = std::stoi(req.get_param_value("rvn"));
		if (req.has_param("profileId")) profile_id = req.get_param_value("profileId");

		if (profile_id == "athena")
			profileData = athenaProfile;
		else if (profile_id == "common_public") 
			profileData = common_public;
		else if (profile_id == "creative") 
			profileData = creative;
		else if (profile_id == "collections") 
			profileData = collections;
		else 
			profileData = common_core;

		if (profileData["rvn"].is_null()) profileData["rvn"] = 1;
		if (profileData["commandRevision"].is_null()) profileData["commandRevision"] = 1;

		json response = {
			{"profileRevision", profileData["rvn"]},
			{"profileId", profile_id},
			{"profileChangesBaseRevision", profileData["rvn"]},
			{"profileChanges", json::array()},
			{"serverTime", "2024-03-09T10:48:34.526Z"},
			{"profileCommandRevision", profileData["commandRevision"]},
			{"responseVersion", 1}
		};

		res.set_content(response.dump(), "application/json");
	});
}