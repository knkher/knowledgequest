#ifndef KQ_B_DS_NTP
#define KQ_B_DS_NTP

namespace kq{
	namespace base{
		namespace datastructures{
			
			struct NodeTraversalStep{
				unsigned long nLink;
				unsigned long nSteps;
			};

			struct NodeTraversalPattern{
				unsigned long m_nSteps;
				NodeTraversalStep * m_ntsSteps;

				NodeTraversalPattern();

				void shrink();
			};
		}
	}
}


#endif