//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Service;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Service = clone_object("/lib/services/researchService");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Service);
}

/////////////////////////////////////////////////////////////////////////////
void ResearchObjectReturnsNullIfNotResearchItem()
{
    ExpectFalse(Service.researchObject("/lib/realizations/player.c"));
    ExpectFalse(Service.researchObject("/lib/not_a_file"));
    ExpectFalse(Service.researchObject("/lib/modules/research.c"));
}

/////////////////////////////////////////////////////////////////////////////
void ResearchObjectReturnsObjectIfValid()
{
    ExpectTrue(Service.researchObject("/lib/modules/research/activeResearchItem.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SuccessfulLookupsPreserveCachedMetadata()
{
    string path = "/lib/tests/support/research/testPointsResearchItem.c";
    object item = Service.researchObject(path);
    mapping prerequisites = Service.getResearchPrerequisites(path);
    prerequisites["cache marker"] = ([ "type":"research" ]);
    ExpectEq(item, Service.researchObject(path));
    ExpectTrue(member(Service.getResearchPrerequisites(path), "cache marker"));
    ExpectFalse(member(item.getPrerequisites(), "cache marker"));
}

/////////////////////////////////////////////////////////////////////////////
void DestructedResearchInvalidatesMetadataBeforeTheNextLookup()
{
    string path = "/lib/tests/support/research/testPointsResearchItem.c";
    object item = Service.researchObject(path);
    mapping prerequisites = Service.getResearchPrerequisites(path);
    prerequisites["cache marker"] = ([ "type":"research" ]);
    destruct(item);
    ExpectFalse(member(Service.getResearchPrerequisites(path), "cache marker"));
    ExpectTrue(Service.validResearch(path));
    ExpectTrue(objectp(Service.researchObject(path)));
}

/////////////////////////////////////////////////////////////////////////////
void CachingATreeNeverMakesItAValidResearchItem()
{
    string path = "/lib/tests/support/research/testResearchTree.c";
    object tree = Service.researchTree(path);
    ExpectTrue(objectp(tree));
    ExpectFalse(Service.validResearch(path));
    ExpectFalse(Service.researchObject(path));
    ExpectEq(tree, Service.researchTree(path));
}
