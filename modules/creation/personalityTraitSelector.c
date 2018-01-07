//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object Dictionary;
private mapping Questionnaire = ([]);
private string *QuestionList = ({});
private string CurrentQuestion;
private string *Results = ({});
private int TestTaken = 0;

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        Dictionary = load_object("/lib/dictionaries/backgroundDictionary.c");
        if (!Dictionary)
        {
            raise_error("personalityTraitQuestionnaire: ERROR - The background dictionary is not present!\n");
        }

        Questionnaire = Dictionary->personalityQuestionnaire();
        if (sizeof(Questionnaire))
        {
            QuestionList = sort_array(m_indices(Questionnaire), (: $1 > $2 :));

            Description = "Personality Test[0m\n\n[0;36m" + 
                Questionnaire[QuestionList[0]]["question"] + "[0m";
            Data = Questionnaire[QuestionList[0]]["answers"];
        }
        AllowUndo = 0;
        HasDescription = 0;
        TestTaken = 0;
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    Results += ({ Data[selection]["type"] });

    int ret = sizeof(QuestionList);
    QuestionList -= ({ QuestionList[0] });
    if (sizeof(QuestionList))
    {
        Description = "Personality Test[0m\n\n[0;36m" +
            Questionnaire[QuestionList[0]]["question"] + "[0m";

        Data = Questionnaire[QuestionList[0]]["answers"];
    }
    else
    {
        TestTaken = 1;
        Dictionary->updateUserPersonality(User, Results);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *selection()
{
    return Results;
}

/////////////////////////////////////////////////////////////////////////////
public int testTaken()
{
    return TestTaken;
}