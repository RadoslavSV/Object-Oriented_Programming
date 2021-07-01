/// Radoslav Velkov, fn 62528, group 1

using namespace std;

#include "ElectionResultsDatabase.cpp"

int main()
{
    SectionVotes s1(5, 1, 2);
    cout<<s1.votesForParty(Party::PARTY1)<<" "<<s1.votesForParty(Party::PARTY2)<<" "<<s1.votesForParty(Party::PARTY3)<<endl;
    SectionVotes s2(6, 10, 12);
    cout<<s2.votesForParty(Party::PARTY1)<<" "<<s2.votesForParty(Party::PARTY2)<<" "<<s2.votesForParty(Party::PARTY3)<<endl;
    SectionVotes s3(20, 24, 8);
    cout<<s3.votesForParty(Party::PARTY1)<<" "<<s3.votesForParty(Party::PARTY2)<<" "<<s3.votesForParty(Party::PARTY3)<<endl;
    SectionVotes s4(14, 15, 18);
    cout<<s4.votesForParty(Party::PARTY1)<<" "<<s4.votesForParty(Party::PARTY2)<<" "<<s4.votesForParty(Party::PARTY3)<<endl;
    SectionVotes s5(5, 10, 0);
    cout<<s5.votesForParty(Party::PARTY1)<<" "<<s5.votesForParty(Party::PARTY2)<<" "<<s5.votesForParty(Party::PARTY3)<<endl;

    std::ofstream outFile;
    outFile.open("filename.txt");
    outFile<<s1.getParty1Votes()<<" "<<s1.getParty2Votes()<<" "<<s1.getParty3Votes()<<endl;
    outFile<<s2.getParty1Votes()<<" "<<s2.getParty2Votes()<<" "<<s2.getParty3Votes()<<endl;
    outFile<<s3.getParty1Votes()<<" "<<s3.getParty2Votes()<<" "<<s3.getParty3Votes()<<endl;
    outFile<<s4.getParty1Votes()<<" "<<s4.getParty2Votes()<<" "<<s4.getParty3Votes()<<endl;
    outFile<<s5.getParty1Votes()<<" "<<s5.getParty2Votes()<<" "<<s5.getParty3Votes()<<endl;

    ElectionResultsDatabase e1;
    cout<<endl<<e1.getParty1TotalVotes()<<" "<<e1.getParty2TotalVotes()<<" "<<e1.getParty3TotalVotes()<<endl<<endl;
    e1.addResultsFromFile("filename.txt");
    cout<<"Number of sections: "<<e1.numberOfSections()<<endl;///5
    cout<<"PARTY1 votes: "<<e1.votesForParty(Party::PARTY1)<<endl;///50
    cout<<"PARTY2 votes: "<<e1.votesForParty(Party::PARTY2)<<endl;///60
    cout<<"PARTY3 votes: "<<e1.votesForParty(Party::PARTY3)<<endl;///40
    cout<<"Winning party: PARTY"<<(int)e1.winningParty()+1<<endl<<endl;///PARTY2

    SectionVotes sS(56, 43, 71);
    cout<<sS.votesForParty(Party::PARTY1)<<" "<<sS.votesForParty(Party::PARTY2)<<" "<<sS.votesForParty(Party::PARTY3)<<endl;
    std::ofstream outFile2;
    outFile2.open("test.txt");
    outFile2<<sS.getParty1Votes()<<" "<<sS.getParty2Votes()<<" "<<sS.getParty3Votes()<<endl;
    e1.addResultsFromFile("test.txt");
    cout<<"Number of sections: "<<e1.numberOfSections()<<endl;///6
    cout<<"PARTY1 votes: "<<e1.votesForParty(Party::PARTY1)<<endl;///106
    cout<<"PARTY2 votes: "<<e1.votesForParty(Party::PARTY2)<<endl;///103
    cout<<"PARTY3 votes: "<<e1.votesForParty(Party::PARTY3)<<endl;///111
    cout<<"Winning party: PARTY"<<(int)e1.winningParty()+1<<endl<<endl;///PARTY3


    return 0;
}



