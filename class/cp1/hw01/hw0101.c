#include <stdio.h>

/*
 * Print Colorful Words
 */
int main()
{
	// Paragraph 1
	printf("Now in those days there was in the land of Helsinki a young scholar named \e[0;34mLinus the Torvald\e[0m. \e[0;34mLinus \e[0mwas a devout man, a disciple of \e[0;34mRMS \e[0mand mighty in the spirit of \e[0;34mTuring \e[0m, \e[0;34mvon Neumann \e[0mand \e[0;34mMoore\e[0m. One day as he was meditating on the Architecture , \e[0;34mLinus \e[0mfell into a trance and was granted a vision. And in the vision he saw a great Penguin , serene and well-favoured , sitting upon an ice floe eating fish. And at the sight of the Penguin \e[0;34mLinus \e[0mwas deeply afraid , and he cried unto the spirits of \e[0;34mTuring \e[0m, \e[0;34mvon Neumann \e[0mand \e[0;34mMoore \e[0mfor an interpretation of the dream.\n");

	// Paragraph 2
	printf("And in the dream the spirits of \e[0;34mTuring \e[0m, \e[0;34mvon Neumann \e[0mand \e[0;34mMoore \e[0manswered and spoke unto him, saying , \e[0;31m\"Fear not, \e[0;34mLinus \e[0;31m, most beloved hacker. You are exceedingly cool and froody. The great Penguin which you see is an Operating System which you shall create and deploy unto the earth. The ice-floe is the earth and all the systems thereof , upon which the Penguin shall rest and rejoice at the completion of its task. And the fish on which the Penguin feeds are the crufty Licensed codebases which swim beneath all the earth’s systems. The Penguin shall hunt and devour all that is crufty , gnarly and bogacious; all code which wriggles like spaghetti , or is infested with blighting creatures , or is bound by grave and perilous Licences shall it capture. And in capturing shall it replicate , and in replicating shall it document , and in documentation shall it bring freedom , serenity and most cool froodiness to the earth and all who code therein.\"\n");

	// Paragraph 3
	printf("\e[0;34mLinus \e[0mrose from meditation and created a tiny Operating System Kernel as the dream had foreshewn him; in the manner of RMS, he released the Kernel unto the World Wide Web for all to take and behold. And in the fulness of Internet Time the Kernel grew and replicated , becoming most cool and exceedingly froody , until at last it was recognised as indeed a great and mighty Penguin , whose name was Tux. And the followers of \e[0;34mLinus \e[0mtook refuge in the Kernel , the Libraries and the Utilities; they installed Distribution after Distribution , and made sacrifice unto the GNU and the Penguin , and gave thanks to the spirits of \e[0;34mTuring \e[0m, \e[0;34mvon Neumann \e[0mand \e[0;34mMoore \e[0m, for their deliverance from the hand of Microsoft. And this was the beginning of the Fourth Age, the age of Open Source.\n");

	// Linus
	printf("\e[0;34mLinus Benedict Torvalds \e[0mis a Finnish software engineer who is the creator and lead developer of the Linux kernel. He was honored, along with \e[0;34mShinya Yamanaka\e[0m, with the 2012 Millennium Technology Prize by the Technology Academy Finland \"\e[0;31min recognition of his creation of a new open source operating system for computers leading to the widely used Linux kernel.\e[0m\"\n");

	// Turing
	printf("\e[0;34mAlan Mathison Turing \e[0mOBE FRS was an English mathematician, computer scientist, logician, cryptanalyst, philosopher and theoretical biologist. \e[0;34mTuring \e[0mwas highly influential in the development of theoretical computer science, providing a formalisation of the concepts of algorithm and computation with the \e[0;34mTuring \e[0mmachine, which can be considered a model of a general-purpose computer. He is widely considered to be the father of theoretical computer science and artificial intelligence.\n");

	// Neumann
	printf("\e[0;34mJohn von Neumann \e[0mwas a Hungarian-American mathematician, physicist, computer scientist, engineer and polymath. He was regarded as having perhaps the widest coverage of any mathematician of his time and was said to have been \"\e[0;31mthe last representative of the great mathematicians who were equally at home in both pure and applied mathematics\e[0m\". He integrated pure and applied sciences.\n");

	// Moore
	printf("\e[0;34mGordon Earle Moore \e[0mwas an American businessman, engineer, and the co-founder and emeritus chairman of Intel Corporation. He proposed Moore's law which makes the observation that the number of transistors in an integrated circuit (IC) doubles about every two years. The prediction has become a target for miniaturization in the semiconductor industry and has had widespread impact in many areas of technological change.\n");

	// RMS
	printf("\e[0;34mRichard Matthew Stallman\e[0m, also known by his initials, \e[0;34mRMS\e[0m, is an American free software movement activist and programmer. He campaigns for software to be distributed in such a manner that its users have the freedom to use, study, distribute, and modify that software. Software that ensures these freedoms is termed free software. \e[0;34mStallman \e[0mlaunched the GNU Project, founded the Free Software Foundation (FSF) in October 1985, developed the GNU Compiler Collection and GNU Emacs, and wrote all versions of the GNU General Public License.\n");

	return 0;
}
