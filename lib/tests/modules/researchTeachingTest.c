//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object User;
object Teacher;
object Room;
string Points = "/lib/tests/support/research/teacherRequiredPointsResearch.c";
string Timed = "/lib/tests/support/research/teacherRequiredTimedResearch.c";

void Setup()
{
    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User.Name("student");
    User.colorConfiguration("none");
    Teacher = clone_object("/lib/tests/support/research/testTeacher.c");
    Room = clone_object("/lib/environment/environment.c");
    move_object(User, Room);
    move_object(Teacher, Room);
}

void CleanUp()
{
    destruct(User);
    if (Teacher)
    {
        destruct(Teacher);
    }
    destruct(Room);
}

void MissingPointsAreReportedWithoutLearningOrRelationshipChanges()
{
    ExpectTrue(User.canResearch(Points));
    ExpectFalse(User.initiateResearch(Points));
    ExpectFalse(User.learnResearchFrom(Teacher, Points));
    ExpectSubStringMatch("2 research points",
        Teacher.lessonRefusal(User, Points));
    ExpectFalse(User.isResearched(Points));
    ExpectEq(0, Teacher.relationshipValue(User, "respect"));
    ExpectEq(0, User.countObservations(([ "type":"training.completed" ])));
    User.addResearchPoints(2);
    ExpectTrue(User.learnResearchFrom(Teacher, Points));
    ExpectEq(0, User.researchPoints());
    ExpectEq(2, Teacher.relationshipValue(User, "respect"));
}

void TeacherRequiredSpecificationRejectsInvalidValues()
{
    object item = clone_object(Points);
    ExpectTrue(item.TestAddSpecification("teacher required", 0));
    ExpectTrue(item.TestAddSpecification("teacher required", 1));
    string error = catch(item.TestAddSpecification(
        "teacher required", 2); nolog);
    ExpectSubStringMatch("must be 0 or 1", error);
    error = catch(item.TestAddSpecification(
        "teacher required", "yes"); nolog);
    ExpectSubStringMatch("must be 0 or 1", error);
    destruct(item);
}

void TimedInstructionCompletesOnceAfterTeacherLeaves()
{
    ExpectFalse(User.initiateResearch(Timed));
    ExpectTrue(User.learnResearchFrom(Teacher, Timed));
    ExpectTrue(User.isResearching(Timed) > 0);
    ExpectFalse(User.learnResearchFrom(Teacher, Timed));
    ExpectEq(0, User.countObservations(([ "type":"training.completed" ])));
    string identity = Teacher.relationshipIdentity();
    destruct(Teacher);
    User.heart_beat();
    User.heart_beat();
    ExpectFalse(User.isResearched(Timed));
    User.heart_beat();
    ExpectTrue(User.isResearched(Timed));
    ExpectEq(2, User.relationshipFrom(identity)["dimensions"]["respect"]);
    ExpectEq(1, User.countObservations(([ "type":"training.completed" ])));
    User.heart_beat();
    ExpectEq(1, User.countObservations(([ "type":"training.completed" ])));
}

void MenuExplainsTeacherRequirementAndDoesNotOfferSelfLearning()
{
    User.addResearchPoints(5);
    object selector = clone_object(
        "/lib/modules/research/researchSubselector.c");
    selector.setSource(Points);
    selector.initiateSelector(User);
    ExpectSubStringMatch("Requires a teacher", User.caughtMessage());
    ExpectSubStringMatch("Seek a teacher", User.caughtMessage());
    ExpectFalse(sizeof(regexp(({ User.caughtMessage() }),
        "Research this item")));
    destruct(selector);
}
