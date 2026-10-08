//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

private object DataAccess;
private object Database;

void Init()
{
    ignoreList += ({ "sqlRows" });
}

private mixed *sqlRows(string query)
{
    mixed *ret = ({ });
    int handle = db_connect(RealmsDatabase());
    db_exec(handle, query);
    if (db_error(handle))
    {
        raise_error(db_error(handle) + "\n");
    }
    mixed row;
    while (row = db_fetch(handle))
    {
        ret += ({ row });
    }
    db_close(handle);
    return ret;
}

void Setup()
{
    setRestoreCaller(this_object());
    Database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    Database.PrepDatabase();
    object authentication = clone_object(
        "/lib/modules/secure/dataServices/authenticationDataService.c");
    authentication.saveUser("gorthaur", "gorthaur", "127.0.0.1");
    destruct(authentication);
    DataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    DataAccess.savePlayerData(Database.Gorthaur());
}

void CleanUp()
{
    if (objectp(DataAccess))
    {
        destruct(DataAccess);
    }
    if (objectp(Database))
    {
        destruct(Database);
    }
}

void DatabaseObservationQueriesUsePersistedRows()
{
    ExpectEq(15, DatabaseVersionFromDatabase());
    ExpectEq(1, DataAccess.countObservationsByPlayer("gorthaur", ([])));
    ExpectTrue(DataAccess.hasObservationByPlayer("gorthaur", ([
        "type": "COMBAT", "weapon": "KATANA", "since": 777,
        "until": 777
    ])));
    ExpectFalse(DataAccess.hasObservationByPlayer("gorthaur", ([
        "type": "comba"
    ])));
    ExpectEq(1, sizeof(DataAccess.queryObservationsByPlayer("gorthaur",
        ([ "weather": "SNOW" ]), 1, 0)));
}

void RecursiveFiltersMatchServiceExactly()
{
    mapping observation = DataAccess.recordObservation("gorthaur", ([
        "ID": "nested", "type": "research.complete",
        "actor": "/actors/Example#BOB", "subject": "Book",
        "timestamp": 999, "location": "/rooms/Example.c",
        "participants": ({ "Bob", "Alice" }),
        "context": ([
            "nested": ([ "name": "Magic", "count": 2,
                "float": 2.5, "tags": ({ "Fire", "Ice", 3 }) ]),
            "structures": ({ ([ "key": "value" ]), ({ 1, 2 }) }),
            "large": 9007199254740993,
            7: ([ "key": "Value" ]),
            "collision": "context", "actor": "shadow",
            "quoted.key\"\\": "Value", "empty": ([])
        ]),
        "metadata": ([ "collision": "metadata", "only": "Meta" ])
    ]));
    mapping *criteria = ({
        ([]), ([ "type": "RESEARCH" ]), ([ "type": "researc" ]),
        ([ "actor": "/ACTORS/EXAMPLE#bob" ]),
        ([ "actor": "shadow" ]), ([ "subject": "BOOK" ]),
        ([ "location": "/ROOMS/EXAMPLE.C" ]),
        ([ "collision": "CONTEXT" ]), ([ "collision": "metadata" ]),
        ([ "only": "META" ]), ([ "quoted.key\"\\": "VALUE" ]),
        ([ "nested": ([ "name": "MAGIC", "count": 2.0 ]) ]),
        ([ "nested": ([ "count": "2" ]) ]),
        ([ "nested": ([ "tags": ({ "Fire", 3.0 }) ]) ]),
        ([ "nested": ([ "tags": ({ "fire" }) ]) ]),
        ([ "structures": ({ ([ "key": "value" ]) }) ]),
        ([ "structures": ({ ({ 1, 2 }) }) ]),
        ([ "large": 9007199254740993 ]),
        ([ "large": 9007199254740992 ]),
        ([ 7: ([ "key": "VALUE" ]) ]),
        ([ "participants": ({ "Bob" }) ]),
        ([ "participants": ({ "BOB" }) ]),
        ([ "empty": ([]) ]), ([ "context": ([]) ]),
        ([ "metadata": ([ "only": "meta" ]) ]),
        ([ "missing": 0 ]), ([ "timestamp": 999.0 ]),
        ([ "timestamp": "999" ]), ([ "since": 999, "until": 999 ]),
        ([ "since": 1000, "until": 999 ]), ([ "since": -1 ]),
        ([ "until": "999" ]), ([ "type": "" ]),
        ([ 1: "numeric key" ])
    });
    foreach(mapping query in criteria)
    {
        int expected = getService("experiences")->matchesObservation(
            observation, query);
        string message = sprintf("criteria %O", query);
        ExpectEq(expected, DataAccess.countObservationsByPlayer("gorthaur",
            query + ([ "ID": "nested" ])), message);
        ExpectEq(expected, DataAccess.hasObservationByPlayer("gorthaur",
            query + ([ "ID": "nested" ])), message);
        ExpectEq(expected, sizeof(DataAccess.queryObservationsByPlayer(
            "gorthaur", query + ([ "ID": "nested" ]), 1, 0)), message);
    }
}

void CircularWindowsAndMalformedCriteriaMatchService()
{
    mapping observation = DataAccess.recordObservation("gorthaur", ([
        "ID": "midnight", "type": "social.smile", "timestamp": 0,
        "context": ([ "minutes after midnight": 1435.5 ])
    ]));
    foreach(mixed window in ({
        ([ "center": 5, "minutes": 10.5 ]),
        ([ "center": 5, "minutes": 10 ]),
        ([ "center": 1435.5, "minutes": 0 ]),
        ([ "center": 715.5, "minutes": 720 ]),
        ([ "center": 1440, "minutes": 5 ]),
        ([ "center": -1, "minutes": 5 ]),
        ([ "center": 0, "minutes": 721 ]),
        ([ "center": 0, "minutes": -1 ]),
        ([ "center": "0", "minutes": 5 ]),
        ([ "center": 0 ]),
        ([ "center": 0, "minutes": 5, "extra": 1 ]),
        0, "bad", ({ 0, 5 })
    }))
    {
        mapping query = ([ "ID": "midnight", "time window": window ]);
        ExpectEq(getService("experiences")->matchesObservation(observation,
            query), DataAccess.countObservationsByPlayer("gorthaur", query),
            sprintf("window %O", window));
    }
    ExpectEq(0, DataAccess.countObservationsByPlayer("gorthaur", ([
        "ID": "midnight", "since": 1, "until": 0
    ])));
    ExpectEq(1, DataAccess.countObservationsByPlayer("gorthaur", ([
        "ID": "midnight", "since": 0, "until": 0
    ])));
    ExpectFalse(DataAccess.hasObservationByPlayer("gorthaur", ([
        "ID": "midnight", "time window": ([ "minutes": 1 ])
    ])));
    ExpectFalse(DataAccess.hasObservationByPlayer("gorthaur", 0));
    foreach(mixed minutes in ({ "0", -1, 1440, ({ 0 }), ([]) }))
    {
        observation = DataAccess.recordObservation("gorthaur", ([
            "type": "invalid.minutes",
            "context": ([ "minutes after midnight": minutes ])
        ]));
        ExpectFalse(DataAccess.hasObservationByPlayer("gorthaur", ([
            "ID": observation["ID"],
            "time window": ([ "center": 0, "minutes": 720 ])
        ])));
    }
    ExpectFalse(DataAccess.hasObservationByPlayer("gorthaur", ([
        "type": "combat", "time window": ([ "center": 0, "minutes": 720 ])
    ])));
}

void PaginationAndExcludedIdsAreAppliedAfterFiltering()
{
    for (int index = 0; index < 8; index++)
    {
        DataAccess.recordObservation("gorthaur", ([
            "ID": sprintf("page-%d", index), "type": "page.event",
            "timestamp": index, "context": ([ "selected": index % 2 ])
        ]));
    }
    mapping query = ([ "type": "PAGE", "selected": 1 ]);
    mapping *rows = DataAccess.queryObservationsByPlayer("gorthaur",
        query, 2, 1);
    ExpectEq(2, sizeof(rows));
    ExpectEq("page-3", rows[0]["ID"]);
    ExpectEq("page-5", rows[1]["ID"]);
    ExpectEq(4, DataAccess.countObservationsByPlayer("gorthaur", query));
    ExpectEq(2, DataAccess.countObservationsByPlayer("gorthaur", query,
        ({ "page-3", "page-5" })));
    rows = DataAccess.queryObservationsByPlayer("gorthaur", query, 1, 1,
        ({ "page-3", "page-5" }));
    ExpectEq("page-7", rows[0]["ID"]);
    ExpectFalse(DataAccess.hasObservationByPlayer("gorthaur", query,
        ({ "page-1", "page-3", "page-5", "page-7" })));
    ExpectEq(0, sizeof(DataAccess.queryObservationsByPlayer("gorthaur",
        query, 1, 4)));
    ExpectEq(3, sizeof(DataAccess.queryObservationsByPlayer("gorthaur",
        query, 0, 1)));
    ExpectEq(4, sizeof(DataAccess.queryObservationsByPlayer("gorthaur",
        query, -100, 0)));
    ExpectEq(0, DataAccess.countObservationsByPlayer("absent", ([])));
}

void RestoreLoadsLatestHundredInChronologicalInsertionOrder()
{
    for (int index = 0; index < 105; index++)
    {
        DataAccess.recordObservation("gorthaur", ([
            "ID": sprintf("history-%d", index), "type": "history.event",
            "timestamp": 105 - index
        ]));
    }
    mapping restored = DataAccess.getPlayerData("gorthaur");
    ExpectEq(1, restored["experiences persisted"]);
    ExpectTrue(restored["playerId"] > 0);
    ExpectEq(100, sizeof(restored["experiences"]));
    ExpectEq("history-5", restored["experiences"][0]["ID"]);
    ExpectEq("history-104", restored["experiences"][99]["ID"]);
    ExpectEq(106, DataAccess.countObservationsByPlayer("gorthaur", ([])));
    ExpectTrue(DataAccess.hasObservationByPlayer("gorthaur", ([
        "ID": "history-0"
    ])));
}

void LegacyPlainAndV1FormatsRemainSearchable()
{
    sqlRows("call saveExperienceObservation('plain',1,'legacy.plain',"
        "'actor','subject','Bob" + "##" + "Alice',10,'location',"
        "'number:=:12" + "##" + "word:=:\"Fire\"',"
        "'flag:=:1');");
    sqlRows("call saveExperienceObservation('v1',1,'legacy.v1','actor',"
        "'subject','@experience-v1@array:12:1:string:1:x',11,'location',"
        "'@experience-v1@mapping:23:1:string:1:xinteger:1:7','');");
    ExpectTrue(DataAccess.hasObservationByPlayer("gorthaur", ([
        "ID": "plain", "number": 12, "word": "fire", "flag": 1,
        "participants": ({ "Bob" })
    ])));
    ExpectFalse(DataAccess.hasObservationByPlayer("gorthaur", ([
        "ID": "plain", "number": "12"
    ])));
    ExpectTrue(DataAccess.hasObservationByPlayer("gorthaur", ([
        "ID": "v1", "x": 7, "participants": ({ "x" })
    ])));
    mapping *rows = DataAccess.queryObservationsByPlayer("gorthaur",
        ([ "type": "legacy" ]), 0, 0);
    ExpectEq(2, sizeof(rows));
    ExpectEq(12, rows[0]["context"]["number"]);
    ExpectEq(7, rows[1]["context"]["x"]);
}

void LegacyArrayNumericMembersKeepStrictTypes()
{
    sqlRows("call saveExperienceObservation('legacy-float',1,'legacy.float',"
        "'actor','','',0,'', '@experience-v1@mapping:40:1:"
        "string:4:tagsarray:16:1:float:6:3.0000',"
        "'');");
    ExpectTrue(DataAccess.hasObservationByPlayer("gorthaur", ([
        "ID": "legacy-float", "tags": ({ 3.0 })
    ])));
    ExpectFalse(DataAccess.hasObservationByPlayer("gorthaur", ([
        "ID": "legacy-float", "tags": ({ 3 })
    ])));
}

void RepeatedSavesRemainAppendOnlyAndIdempotent()
{
    mapping observation = DataAccess.recordObservation("gorthaur", ([
        "ID": "unchanged", "type": "append.original",
        "context": ([ "state": "original" ])
    ]));
    DataAccess.recordObservation("gorthaur", observation + ([
        "type": "append.replaced", "context": ([ "state": "changed" ])
    ]));
    ExpectEq(1, DataAccess.countObservationsByPlayer("gorthaur", ([
        "type": "append.original", "state": "original"
    ])));
    ExpectFalse(DataAccess.hasObservationByPlayer("gorthaur", ([
        "type": "append.replaced"
    ])));
    ExpectEq(2, DataAccess.countObservationsByPlayer("gorthaur", ([])));
}

void QueryValuesCannotInjectSql()
{
    string payload = "' OR 1=1; -- \\\" %_";
    DataAccess.recordObservation("gorthaur", ([
        "ID": "quoted", "type": "literal.%_.event",
        "subject": payload, "context": ([ payload: payload ])
    ]));
    ExpectEq(1, DataAccess.countObservationsByPlayer("gorthaur", ([
        "type": "literal.%_", "subject": payload, payload: payload
    ])));
    ExpectEq(0, DataAccess.countObservationsByPlayer("gorthaur", ([
        "type": "literal"
    ]), ({ "quoted" })));
    ExpectEq(0, DataAccess.countObservationsByPlayer("gorthaur", ([
        "subject": "' OR 1=1 --"
    ])));
    ExpectEq(0, DataAccess.countObservationsByPlayer("' OR 1=1 --", ([])));
    ExpectEq(2, DataAccess.countObservationsByPlayer("gorthaur", ([]),
        ({ payload })));
}

void CompositeIndexesAreAvailableToQueryPlanner()
{
    sqlRows("insert into experienceObservations (observationKey, playerId, "
        "observationType, actor, observationTime) select "
        "concat('index-', firstDigit.number, secondDigit.number, "
        "thirdDigit.number), 1, 'noise.event', 'actor', "
        "firstDigit.number * 100 + secondDigit.number * 10 + "
        "thirdDigit.number from "
        "(select 0 number union all select 1 union all select 2 "
        "union all select 3 union all select 4 union all select 5 "
        "union all select 6 union all select 7 union all select 8 "
        "union all select 9) firstDigit cross join "
        "(select 0 number union all select 1 union all select 2 "
        "union all select 3 union all select 4 union all select 5 "
        "union all select 6 union all select 7 union all select 8 "
        "union all select 9) secondDigit cross join "
        "(select 0 number union all select 1 union all select 2 "
        "union all select 3 union all select 4 union all select 5 "
        "union all select 6 union all select 7 union all select 8 "
        "union all select 9) thirdDigit;");
    mixed *typePlan = sqlRows("explain select count(*) from "
        "experienceObservations where playerId=1 and "
        "(searchType='combat' or (searchType >= 'combat.' and "
        "searchType < 'combat/')) and observationTime >= 777 and "
        "observationMatches(searchDocument, "
        "observationDecode('mapping:2:0:')) = 1;");
    mixed *timePlan = sqlRows("explain select exists(select 1 from "
        "experienceObservations where playerId=1 and observationTime=777);");
    ExpectSubStringMatch("experience_player_type_time",
        typePlan[0][6]);
    ExpectSubStringMatch("experience_player_time", timePlan[1][6]);
}

void MigrationBackfillsExistingV2V1AndPlainRows()
{
    LegacyPlainAndV1FormatsRemainSearchable();
    sqlRows("drop trigger observationSearchInsert;");
    sqlRows("drop trigger observationSearchUpdate;");
    sqlRows("alter table experienceObservations "
        "drop key experience_player_type_time, "
        "drop key experience_player_time, drop column searchDocument, "
        "drop column searchType, drop key experience_observationKey_unique, "
        "drop column observationKey;");
    sqlRows("update versionInfo set id=12 "
        "where versionType='database';");
    int handle = db_connect(RealmsDatabase());
    db_close(handle);
    ExpectEq(15, DatabaseVersionFromDatabase());
    ExpectEq(3, DataAccess.countObservationsByPlayer("gorthaur", ([])));
    ExpectTrue(DataAccess.hasObservationByPlayer("gorthaur", ([
        "type": "COMBAT", "context": ([ "weather": "SNOW" ])
    ])));
    ExpectTrue(DataAccess.hasObservationByPlayer("gorthaur", ([
        "number": 12, "word": "fire"
    ])));
    ExpectTrue(DataAccess.hasObservationByPlayer("gorthaur", ([
        "x": 7
    ])));
}