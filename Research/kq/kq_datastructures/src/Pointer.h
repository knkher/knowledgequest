#ifndef POINTER_H_
#define POINTER_H_

namespace kq{
	namespace datastructures{
		class Pointer{

		public:
			void * m_pLocation;
			unsigned long m_uSize;
			
			void pointTo(void * pLocation = 0, unsigned long uSize = 0);

			int bIsDataEqual(const Pointer & pOther);

			Pointer * getDataCopy();			

		public:
			Pointer(void);
			Pointer(void * pLocation, unsigned long uSize);
			Pointer(Pointer &pointer);
		public:
			virtual ~Pointer(void);
		};
	}
};

#endif