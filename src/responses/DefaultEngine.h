namespace DefaultEngine
{
	std::string ini = R"(
		[ConsoleVariables]
		FortMatchmakingV2.EnableContentBeacon=0
		FortMatchmakingV2.ContentBeaconFailureCancelsMatchmaking=0

		[Core.Log]
		LogHttp=error
		LogXmpp=error
		LogBeacon=verbose
		LogQos=error
		LogOnline=verbose
		LogOnlineCloud=verbose
		LogOnlineGame=verbose
		LogSourceControl=verbose
		LogUAC=verbose
		LogBattlEye=verbose
		LogEasyAntiCheatServer=verbose
		LogEasyAntiCheatClient=verbose
		LogFortAnalytics=verbose
		LogEpicCMS=verbose
		LogNetPlayerMovement=verbose
		LogDerivedDataCache=verbose
		LogOnlineDataAssetDirectory=verbose
		LogContentBeacon=verbose
		LogBPSInstallerConfig=verbose

		[PatchCheck]
		ModuleName=FortnitePatchCheck
		bCheckPlatformOSSForUpdate=false
		bCheckOSSForUpdate=false

		[XMPP]
		bEnableWebsockets=false
	
		[/Script/Qos.QosRegionManager]
		!RegionDefinitions=ClearArray
		+RegionDefinitions=(DisplayName=NSLOCTEXT("MMRegion", "DC", "DC"), RegionId="DC", bEnabled=true, bVisible=true, bAutoAssignable=true)
	)";

	std::string name = "DefaultEngine.ini";
	std::string sha1 = "88bef9a6b57ff7eec9a441f3791c1b024519256a";
	std::string sha256 = "760bb6529456a6af328293fa446eebd62e3ef3c44e1065ecd2a36978cc1e6ada";
}