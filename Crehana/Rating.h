#ifndef __RATING_H__
#define __RATING_H__
class Rating
{
private:
	float Quantity;
public:
	Rating();
	Rating(float Quantity);
	~Rating();
	void setQuantity(float Quantity);
	float getQuantity();
};
Rating::Rating() {

}
Rating::Rating(float Quantity) {
	this->Quantity = Quantity;
}
Rating::~Rating() {

}
void Rating::setQuantity(float Quantity) {
	this->Quantity = Quantity;
}
float Rating::getQuantity() {
	return Quantity;
}
#endif // !__RATING__H_