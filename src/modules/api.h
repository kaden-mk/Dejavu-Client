void initApi()
{
	server.Get("/fortnite/api/cloudstorage/system", [](const Request& req, Response& res)
	{
		json j = json::array({
			{
				{"uniqueFilename", DefaultGame::name},
				{"filename", DefaultGame::name},
				{"hash", DefaultGame::sha1},
				{"hash256", DefaultGame::sha256},
				{"length", DefaultGame::ini.size()},
				{"contentType", "application/octet-stream"},
				{"uploaded", "2021-01-03T21:17:16.703Z"},
				{"storageType", "S3"},
				{"doNotCache", false}
			},
			{
				{"uniqueFilename", DefaultEngine::name},
				{"filename", DefaultEngine::name},
				{"hash", DefaultEngine::sha1},
				{"hash256", DefaultEngine::sha256},
				{"length", DefaultEngine::ini.size()},
				{"contentType", "application/octet-stream"},
				{"uploaded", "2021-01-03T21:17:16.703Z"},
				{"storageType", "S3"},
				{"doNotCache", false}
			},
			{
				{"uniqueFilename", DefaultRuntimeOptions::name},
				{"filename", DefaultRuntimeOptions::name},
				{"hash", DefaultRuntimeOptions::sha1},
				{"hash256", DefaultRuntimeOptions::sha256},
				{"length", DefaultRuntimeOptions::ini.size()},
				{"contentType", "application/octet-stream"},
				{"uploaded", "2021-01-03T21:17:16.703Z"},
				{"storageType", "S3"},
				{"doNotCache", false}
			}
		});
		res.set_content(j.dump(), "application/json");
	});

	server.Get("/fortnite/api/cloudstorage/system/DefaultGame.ini", [](const Request& req, Response& res)
	{
		res.set_content(DefaultGame::ini, "application/octet-stream");
	});

	server.Get("/fortnite/api/cloudstorage/system/DefaultEngine.ini", [](const Request& req, Response& res)
	{
		res.set_content(DefaultEngine::ini, "application/octet-stream");
	});

	server.Get("/fortnite/api/cloudstorage/system/DefaultRuntimeOptions.ini", [](const Request& req, Response& res)
	{
		res.set_content(DefaultRuntimeOptions::ini, "application/octet-stream");
	});

	server.Get("/account/api/oauth/verify", [](const Request& req, Response& res)
	{
		auto token = static_cast<std::string>(req.get_header_value("Authorization"));
		token.erase(token.begin(), token.begin() + 7);
		json j = {
			{"access_token", token},
			{"expires_in", 28800},
			{"expires_at", "9999-12-31T23:59:59.999Z"},
			{"token_type", "bearer"},
			{"refresh_token", "refreshtoken"},
			{"refresh_expires", 115200},
			{"refresh_expires_at", "9999-12-31T23:59:59.999Z"},
			{"account_id", "accountid"},
			{"client_id", "clientid"},
			{"internal_client", "true"},
			{"client_service", "fortnite"},
			{"displayName", "Player"},
			{"app", "fortnite"},
			{"in_app_id", "inappid"},
			{"device_id", "deviceid"}
		};
		res.set_content(j.dump(), "application/json");
	});

	server.Post("/account/api/oauth/token", [](const Request& req, Response& res)
	{
		json j;
		if (req.get_param_value("grant_type") == "client_credentials")
		{
			j = {
				{"access_token", "eg1~h1e35h4tr5h456r4h75r4h8r4h5r45h4r5"},
				{"expires_in", 28800},
				{"expires_at", "9999-12-31T23:59:59.999Z"},
				{"token_type", "bearer"},
				{"client_id", "clientid"},
				{"internal_client", "true"},
				{"client_service", "fortnite"},
			};
		}
		else
		{
			j = {
				{"access_token", "eg1~h1e35h4tr5h456r4h75r4h8r4h5r45h4r5"},
				{"expires_in", 28800},
				{"expires_at", "9999-12-31T23:59:59.999Z"},
				{"token_type", "bearer"},
				{"account_id", "Player"},
				{"client_id", "clientid"},
				{"internal_client", true},
				{"client_service", "fortnite"},
				{"displayName", "Player"},
				{"app", "fortnite"},
				{"in_app_id", "Player"},
				{"device_id", "deviceid"}
			};
		}

		res.set_content(j.dump(), "application/json");
	});
}