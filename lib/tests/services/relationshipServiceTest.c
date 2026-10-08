//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Service;
object Source;
object Target;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Service = clone_object("/lib/services/relationshipService.c");
    Source = clone_object("/lib/tests/support/services/mockPlayer.c");
    Target = clone_object("/lib/tests/support/services/mockPlayer.c");

    Source.Name("gorthaur");
    Target.Name("fred");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Source);
    destruct(Target);
    destruct(Service);
}

/////////////////////////////////////////////////////////////////////////////
void RelationshipUpdatesAreDirectional()
{
    Service.updateRelationship(Source, Target, ([ "trust": 5 ]), ([]), ([]),
        "conversation.greet");

    ExpectEq(5, Service.relationshipDimensionToward(Source, Target, "trust"));
    ExpectEq(0, Service.relationshipDimensionToward(Target, Source, "trust"));
}

/////////////////////////////////////////////////////////////////////////////
void RelationshipDimensionsAccumulate()
{
    Service.updateRelationship(Source, Target, ([ "trust": 3 ]), ([]), ([]),
        "conversation.greet");
    Service.updateRelationship(Source, Target, ([ "trust": 2, "respect": 1 ]),
        ([]), ([]), "combat.rescue");

    ExpectEq(5, Service.relationshipDimensionToward(Source, Target, "trust"));
    ExpectEq(1, Service.relationshipDimensionToward(Source, Target, "respect"));
}

/////////////////////////////////////////////////////////////////////////////
void QueryRelationshipsReturnsMatchingDimensionThresholds()
{
    Service.updateRelationship(Source, Target, ([ "trust": 5, "respect": 2 ]),
        ([]), ([]), "conversation.greet");

    mapping *matches = Service.queryRelationships(Source,
        ([ "trust": 4, "respect": 1 ]));

    ExpectEq(1, sizeof(matches));
    ExpectEq(5, matches[0]["dimensions"]["trust"]);
}

/////////////////////////////////////////////////////////////////////////////
void RelationshipHistoryBelongsToExperiences()
{
    Service.updateRelationship(Source, Target, ([ "trust": 4 ]),
        ([ "location": "inn" ]),
        ([ "note": "first impression" ]),
        "conversation.greet");

    ExpectEq(0, sizeof(Service.relationshipHistoryFor(Source, Target, ([]))));
    Source.recordRelationshipInteraction(Target, "gift.given",
        ([ "gratitude":5 ]), ([ "item":"amulet" ]));
    ExpectEq(1, Source.countObservations(([ "type":"gift.given" ])));
}

/////////////////////////////////////////////////////////////////////////////
void ValuesRespectDimensionSpecificBounds()
{
    Service.modify(Source, Target, "trust", 1000);
    Service.modify(Source, Target, "fear", -1000);
    ExpectEq(100, Source.relationshipValue(Target, "trust"));
    ExpectEq(0, Source.relationshipValue(Target, "fear"));
    Service.modify(Source, Target, "trust", -1000);
    ExpectEq(-100, Source.relationshipValue(Target, "trust"));
}

/////////////////////////////////////////////////////////////////////////////
void InvalidBatchIsRejectedWithoutPartialMutation()
{
    string error = catch(Service.updateRelationship(Source, Target,
        ([ "trust":5, "bogus":10 ]), ([]), ([]), "test"); nolog);
    ExpectTrue(stringp(error));
    ExpectFalse(Source.hasRelationship(Target));
    error = catch(Service.modify(Source, Source, "trust", 5); nolog);
    ExpectTrue(stringp(error));
}

/////////////////////////////////////////////////////////////////////////////
void ReturnedStateDoesNotPermitExternalMutation()
{
    mapping record = Service.modify(Source, Target, "trust", 5);
    record["dimensions"]["trust"] = -100;
    ExpectEq(5, Source.relationshipValue(Target, "trust"));
}

/////////////////////////////////////////////////////////////////////////////
void ServiceInstancesUseModuleOwnedTruth()
{
    Service.modify(Source, Target, "trust", 5);
    object second = clone_object("/lib/services/relationshipService.c");
    second.modify(Source, Target, "trust", 2);
    ExpectEq(7, Service.relationshipDimensionToward(Source, Target, "trust"));
    destruct(second);
}

/////////////////////////////////////////////////////////////////////////////
void DerivedClassificationTracksCurrentValues()
{
    ExpectEq("stranger", Source.relationshipType(Target));
    Service.updateRelationship(Source, Target,
        ([ "trust":60, "respect":50, "affection":40 ]),
        ([]), ([]), "test");
    ExpectEq("friend", Source.relationshipType(Target));
    Source.setRelationshipValue(Target, "trust", -80);
    ExpectEq("enemy", Source.relationshipType(Target));
}

/////////////////////////////////////////////////////////////////////////////
void DimensionIsolationAndMissingValuesUseZeroBaseline()
{
    Service.modify(Source, Target, "trust", 10);
    ExpectEq(0, Source.relationshipValue(Target, "respect"));
    object third = clone_object("/lib/tests/support/services/mockPlayer.c");
    third.Name("third");
    ExpectEq(0, Source.relationshipValue(third, "trust"));
    ExpectTrue(Service.meetsCondition(Source, ([
        "target":Service.identity(third),
        "direction":"toward",
        "dimension":"trust",
        "minimum":0,
        "maximum":0
    ])));
    destruct(third);
}

/////////////////////////////////////////////////////////////////////////////
void ServiceAliasesResolveToTheSameStatelessInstance()
{
    ExpectEq(getService("relationship"), getService("relationships"));
}
