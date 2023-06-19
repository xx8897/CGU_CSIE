/*
 * SPDX-License-Identifier: Apache-2.0
 */

'use strict';

const { ChaincodeStub, ClientIdentity } = require('fabric-shim');
const { MyCarContract } = require('..');
const winston = require('winston');

const chai = require('chai');
const chaiAsPromised = require('chai-as-promised');
const sinon = require('sinon');
const sinonChai = require('sinon-chai');

chai.should();
chai.use(chaiAsPromised);
chai.use(sinonChai);

class TestContext {

    constructor() {
        this.stub = sinon.createStubInstance(ChaincodeStub);
        this.clientIdentity = sinon.createStubInstance(ClientIdentity);
        this.logger = {
            getLogger: sinon.stub().returns(sinon.createStubInstance(winston.createLogger().constructor)),
            setLevel: sinon.stub(),
        };
    }

}

describe('MyCarContract', () => {

    let contract;
    let ctx;

    beforeEach(() => {
        contract = new MyCarContract();
        ctx = new TestContext();
        ctx.stub.getState.withArgs('1001').resolves(Buffer.from('{"value":"my car 1001 value"}'));
        ctx.stub.getState.withArgs('1002').resolves(Buffer.from('{"value":"my car 1002 value"}'));
    });

    describe('#myCarExists', () => {

        it('should return true for a my car', async () => {
            await contract.myCarExists(ctx, '1001').should.eventually.be.true;
        });

        it('should return false for a my car that does not exist', async () => {
            await contract.myCarExists(ctx, '1003').should.eventually.be.false;
        });

    });

    describe('#createMyCar', () => {

        it('should create a my car', async () => {
            await contract.createMyCar(ctx, '1003', 'my car 1003 value');
            ctx.stub.putState.should.have.been.calledOnceWithExactly('1003', Buffer.from('{"value":"my car 1003 value"}'));
        });

        it('should throw an error for a my car that already exists', async () => {
            await contract.createMyCar(ctx, '1001', 'myvalue').should.be.rejectedWith(/The my car 1001 already exists/);
        });

    });

    describe('#readMyCar', () => {

        it('should return a my car', async () => {
            await contract.readMyCar(ctx, '1001').should.eventually.deep.equal({ value: 'my car 1001 value' });
        });

        it('should throw an error for a my car that does not exist', async () => {
            await contract.readMyCar(ctx, '1003').should.be.rejectedWith(/The my car 1003 does not exist/);
        });

    });

    describe('#updateMyCar', () => {

        it('should update a my car', async () => {
            await contract.updateMyCar(ctx, '1001', 'my car 1001 new value');
            ctx.stub.putState.should.have.been.calledOnceWithExactly('1001', Buffer.from('{"value":"my car 1001 new value"}'));
        });

        it('should throw an error for a my car that does not exist', async () => {
            await contract.updateMyCar(ctx, '1003', 'my car 1003 new value').should.be.rejectedWith(/The my car 1003 does not exist/);
        });

    });

    describe('#deleteMyCar', () => {

        it('should delete a my car', async () => {
            await contract.deleteMyCar(ctx, '1001');
            ctx.stub.deleteState.should.have.been.calledOnceWithExactly('1001');
        });

        it('should throw an error for a my car that does not exist', async () => {
            await contract.deleteMyCar(ctx, '1003').should.be.rejectedWith(/The my car 1003 does not exist/);
        });

    });

});
