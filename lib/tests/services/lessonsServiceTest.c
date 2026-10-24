//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Service;
string Tree = "/lib/tests/support/research/deferredResearchTree.c";
string Points =
    "/lib/tests/support/research/teacherRequiredPointsResearch.c";
string Root = "/lib/tests/support/research/testTreeRoot.c";

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Service = clone_object("/lib/services/lessonsService.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Service);
}

/////////////////////////////////////////////////////////////////////////////
void CurriculumContainsPathsWithoutItsRootAndReturnsACopy()
{
    string *paths = Service.lessonPaths(Tree);
    ExpectEq(({ Points }), paths);
    paths[0] = "changed";
    ExpectEq(({ Points }), Service.lessonPaths(Tree));
    object tree = getService("research")->researchTree(Tree);
    string *members = tree.getResearchPaths();
    ExpectEq(2, sizeof(members));
    members[0] = "changed";
    ExpectTrue(member(tree.getResearchPaths(), Root) >= 0);
}

/////////////////////////////////////////////////////////////////////////////
void DestroyingATreeRebuildsTheCachedCurriculum()
{
    ExpectEq(({ Points }), Service.lessonPaths(Tree));
    object tree = getService("research")->researchTree(Tree);
    ExpectTrue(tree.addResearchElement(
        "/lib/tests/support/research/teacherRequiredTimedResearch.c"));
    destruct(tree);
    ExpectEq(({ Points }), Service.lessonPaths(Tree));
    ExpectTrue(objectp(find_object(Tree)));
}

/////////////////////////////////////////////////////////////////////////////
void NamesAreExactAndRefreshAfterTheLessonIsDestroyed()
{
    string name = Service.lessonName(Points);
    ExpectEq(({ Points }), Service.matchingLessons(({ Points }), name));
    ExpectEq(({ Points }), Service.matchingLessons(({ Points }),
        upper_case(name)));
    ExpectEq(({}), Service.matchingLessons(({ Points }), "unknown"));
    destruct(find_object(Points));
    ExpectEq(name, Service.lessonName(Points));
    ExpectTrue(find_object(Points));
}

/////////////////////////////////////////////////////////////////////////////
void LessonLookupsReuseTheSameInstanceAcrossConsumers()
{
    object lesson = Service.lessonObject(Points);
    ExpectTrue(objectp(lesson));
    ExpectEq(lesson, Service.lessonObject(Points));
    ExpectEq(lesson, Service.lessonObject(Points));
    ExpectEq(lesson, find_object(Points));
    ExpectEq(lesson, getService("research")->researchObject(Points));
    ExpectEq(lesson, getService("lessons")->lessonObject(Points));
    ExpectEq(lesson.query("name"), Service.lessonName(Points));
    ExpectEq(lesson, Service.lessonObject(Points));
}

/////////////////////////////////////////////////////////////////////////////
void DestroyingALessonReplacesTheCachedInstanceAndName()
{
    object lesson = Service.lessonObject(Points);
    string name = Service.lessonName(Points);
    destruct(lesson);
    ExpectFalse(lesson);
    object replacement = Service.lessonObject(Points);
    ExpectTrue(objectp(replacement));
    ExpectEq(replacement, find_object(Points));
    ExpectEq(replacement, Service.lessonObject(Points));
    ExpectEq(name, Service.lessonName(Points));
    ExpectEq(replacement, getService("lessons")->lessonObject(Points));
}

/////////////////////////////////////////////////////////////////////////////
void InvalidTreesAndLessonsRaiseExplicitErrors()
{
    string error = catch(Service.lessonPaths("/no-such-tree.c"); nolog);
    ExpectSubStringMatch("Invalid research tree", error);
    error = catch(Service.lessonObject(Tree); nolog);
    ExpectSubStringMatch("Invalid research lesson", error);
}

/////////////////////////////////////////////////////////////////////////////
void DeferredTreesRejectMalformedPathsDuplicatesAndCycles()
{
    object tree = getService("research")->researchTree(Tree);
    string error = catch(tree.addResearchElement("missing"); nolog);
    ExpectSubStringMatch("research element must exist", error);
    error = catch(tree.addResearchElement(Points); nolog);
    ExpectSubStringMatch("already a member", error);
    error = catch(tree.addChild(Root, Points); nolog);
    ExpectSubStringMatch("infinite recursion", error);
    error = catch(tree.addChild("/missing.c", Root); nolog);
    ExpectSubStringMatch("unique valid researchItem", error);
}

/////////////////////////////////////////////////////////////////////////////
void InvalidDeferredElementsFailWhenResolvedInsteadOfDisappearing()
{
    object tree = clone_object(Tree);
    ExpectTrue(tree.addResearchElement("/missing.c"));
    string error = catch(tree.getResearchItem("/missing.c"); nolog);
    ExpectSubStringMatch("is not a valid research item", error);
    ExpectTrue(tree.addResearchElement(
        "/lib/modules/research/researchTree.c"));
    error = catch(tree.getResearchItem(
        "/lib/modules/research/researchTree.c"); nolog);
    ExpectSubStringMatch("is not a valid research item", error);
    destruct(tree);
}
