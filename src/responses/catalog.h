json catalog = R"(
{
  "refreshIntervalHrs": 24,
  "dailyPurchaseHrs": 24,
  "expiration": "9999-12-31T00:00:00.000Z",
  "storefronts": [
    {
      "name": "BRDailyStorefront",
      "catalogEntries": []
    },
    {
      "name": "BRWeeklyStorefront",
      "catalogEntries": []
    },
    {
      "name": "BRSeasonStorefront",
      "catalogEntries": [
        {
          "devName": "[VIRTUAL]1 x Aerial Assault One for 500 MtxCurrency",
          "offerId": "v2:/km5i4yvqxd8sqav1r4tk4qlsjolqkd7o5g25p6elcbqwtlsulqnu6hv84ug58i9c",
          "fulfillmentIds": [],
          "dailyLimit": -1,
          "weeklyLimit": -1,
          "monthlyLimit": -1,
          "categories": [
            "Panel 1"
          ],
          "prices": [
            {
              "currencyType": "MtxCurrency",
              "currencySubType": "",
              "regularPrice": 500,
              "finalPrice": 500,
              "saleExpiration": "9999-12-31T23:59:59.999Z",
              "basePrice": 500
            }
          ],
          "meta": {},
          "matchFilter": "",
          "filterWeight": 0,
          "appStoreId": [],
          "requirements": [
            {
              "requirementType": "DenyOnItemOwnership",
              "requiredId": "AthenaGlider:Glider_ID_001",
              "minQuantity": 1
            }
          ],
          "offerType": "StaticPrice",
          "giftInfo": {},
          "refundable": true,
          "metaInfo": [],
          "displayAssetPath": "/Game/Catalog/DisplayAssets/DA_Featured_GliderMiG.DA_Featured_GliderMiG",
          "itemGrants": [
            {
              "templateId": "AthenaGlider:Glider_ID_001",
              "quantity": 1
            }
          ],
          "sortPriority": -1,
          "catalogGroupPriority": 0
        },
        {
          "devName": "[VIRTUAL]1 x Aerial Assault Trooper for 1200 MtxCurrency",
          "offerId": "v2:/6icfozpr9g7o1gxperhc5rl8dty1o4rzlszmiky0iafc012w5gcdczvsvbvqw8fv",
          "fulfillmentIds": [],
          "dailyLimit": -1,
          "weeklyLimit": -1,
          "monthlyLimit": -1,
          "categories": [
            "Panel 2"
          ],
          "prices": [
            {
              "currencyType": "MtxCurrency",
              "currencySubType": "",
              "regularPrice": 1200,
              "finalPrice": 1200,
              "saleExpiration": "9999-12-31T23:59:59.999Z",
              "basePrice": 1200
            }
          ],
          "meta": {},
          "matchFilter": "",
          "filterWeight": 0,
          "appStoreId": [],
          "requirements": [
            {
              "requirementType": "DenyOnItemOwnership",
              "requiredId": "AthenaCharacter:CID_017_Athena_Commando_M",
              "minQuantity": 1
            }
          ],
          "offerType": "StaticPrice",
          "giftInfo": {},
          "refundable": true,
          "metaInfo": [],
          "displayAssetPath": "/Game/Catalog/DisplayAssets/DA_Featured_SMaleHID017.DA_Featured_SMaleHID017",
          "itemGrants": [
            {
              "templateId": "AthenaCharacter:CID_017_Athena_Commando_M",
              "quantity": 1
            }
          ],
          "sortPriority": -1,
          "catalogGroupPriority": 0
        },
        {
          "devName": "[VIRTUAL]1 x Renegade Raider for 1200 MtxCurrency",
          "offerId": "v2:/erpaf2rm87d5xgdtqpgx3qyqwrjmn5gsog0cu792enrxh9k1jckzjvgvn6qu7fq7",
          "fulfillmentIds": [],
          "dailyLimit": -1,
          "weeklyLimit": -1,
          "monthlyLimit": -1,
          "categories": [
            "Panel 3"
          ],
          "prices": [
            {
              "currencyType": "MtxCurrency",
              "currencySubType": "",
              "regularPrice": 1200,
              "finalPrice": 1200,
              "saleExpiration": "9999-12-31T23:59:59.999Z",
              "basePrice": 1200
            }
          ],
          "meta": {},
          "matchFilter": "",
          "filterWeight": 0,
          "appStoreId": [],
          "requirements": [
            {
              "requirementType": "DenyOnItemOwnership",
              "requiredId": "AthenaCharacter:CID_028_Athena_Commando_F",
              "minQuantity": 1
            }
          ],
          "offerType": "StaticPrice",
          "giftInfo": {},
          "refundable": true,
          "metaInfo": [],
          "displayAssetPath": "/Game/Catalog/DisplayAssets/DA_Featured_SFemaleHID028.DA_Featured_SFemaleHID028",
          "itemGrants": [
            {
              "templateId": "AthenaCharacter:CID_028_Athena_Commando_F",
              "quantity": 1
            }
          ],
          "sortPriority": -1,
          "catalogGroupPriority": 0
        },
        {
          "devName": "[VIRTUAL]1 x Raider's Revenge for 1500 MtxCurrency4",
          "offerId": "v2:/w6aq7n8ma7gz342b4wus42hmkqz8suurbdvjo51ug6on7j9rme577eax92rlt4g9",
          "fulfillmentIds": [],
          "dailyLimit": -1,
          "weeklyLimit": -1,
          "monthlyLimit": -1,
          "categories": [
            "Panel 4"
          ],
          "prices": [
            {
              "currencyType": "MtxCurrency",
              "currencySubType": "",
              "regularPrice": 1500,
              "finalPrice": 1500,
              "saleExpiration": "9999-12-31T23:59:59.999Z",
              "basePrice": 1500
            }
          ],
          "meta": {},
          "matchFilter": "",
          "filterWeight": 0,
          "appStoreId": [],
          "requirements": [
            {
              "requirementType": "DenyOnItemOwnership",
              "requiredId": "AthenaPickaxe:Pickaxe_Lockjaw",
              "minQuantity": 1
            }
          ],
          "offerType": "StaticPrice",
          "giftInfo": {},
          "refundable": true,
          "metaInfo": [],
          "displayAssetPath": "/Game/Catalog/DisplayAssets/DA_Featured_PickaxeLockjaw.DA_Featured_PickaxeLockjaw",
          "itemGrants": [
            {
              "templateId": "AthenaPickaxe:Pickaxe_Lockjaw",
              "quantity": 1
            }
          ],
          "sortPriority": -1,
          "catalogGroupPriority": 0
        }
      ]
    }
  ]
}
)"_json;